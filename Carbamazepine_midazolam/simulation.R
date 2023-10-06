library(tidyverse)
library(mrgsolve)
library(PKPDmisc)
library(cowplot)
library(NonCompart)

mod <- mread_cache("DrugA/MM_induction.cpp")

# Default simulation scenario
amt <- 200       #input(Simulation)
ii <- 12     #input(Simulation)
addl <- 14    #input(Simulation)
start_time <- 0    #input(Simulation)

# Change of Km for simulation (default Km = 5.2, conventional model Km = 100000)

idata <- data.frame(ID = 1:20, Km_3a4 = c(seq(0.001, 30, length.out = 10), seq(100, 1000, length.out = 10))) 

data <- mod %>%
    idata_set(idata) %>%
    ev(amt = amt, ii = ii, addl = addl) %>%
    mrgsim(end = ii*(addl+1), maxsteps = 1000000) 

data_tidy <- data %>%
    as.data.frame() %>%
    select(ID, time, Cp, TVCL_result, Fg_qgut_result) %>%
    left_join(idata, by = "ID") 

data_tidy %>%
  ggplot(aes(x = time, y = TVCL_result, color = factor(Km_3a4))) +
  geom_line() +
  facet_wrap(~Km_3a4, ncol = 3, scales = "free_y") +
  theme_bw()

data_tidy %>%
  ggplot(aes(x = time, y = Fg_qgut_result, color = factor(Km_3a4))) +
  geom_line() +
  facet_wrap(~Km_3a4, ncol = 3, scales = "free_y") +
  theme_bw()


data_tidy_sim <- data_tidy %>%
  filter(time <= ii | time >= ii*addl) %>%
  mutate(SS = ifelse(time <= ii, "Single", "Multiple")) %>%
  mutate(TAD = ifelse(time <= ii, time, time - ii*addl)) 

data_tidy_sim %>%
  # filter(SS == "Multiple") %>%
  ggplot(aes(x = TAD, y = Cp, color = SS)) +
  geom_line() +
  facet_wrap(~Km_3a4, ncol = 3) +
  theme_bw()

aucs <- data_tidy_sim %>%
  tblNCA(key = c("Km_3a4", "SS"), colTime = "time", colConc = "Cp", R2ADJ = -1) %>%
  select(Km_3a4, SS, CMAX, AUCLST, AUCIFO) %>%
  gather(key = "PK", value = "value", -Km_3a4, -SS) %>%
  spread(key = "SS", value = c("value")) %>%
  mutate(percent_increase = Multiple / Single * 100) 

aucs %>%
  filter(PK == "AUCLST") %>%
  ggplot(aes(x = Km_3a4, y = percent_increase)) +
  geom_line() +
  geom_point() +
  theme_bw()
