library(tidyverse)
library(mrgsolve)
library(PKPDmisc)
library(cowplot)
library(NonCompart)

mod <- mread_cache("Carbamazepine/MM_induction.cpp")

MW <- 236.27       #input(Simulation)
logP <- 2.007     #input(Simulation)
pKa <- 11.83
type <- "acid"
fu <- 0.243
method <- "R&R"
GFRf <- 0.024 
Vmax_ugt2b7 <- 3.5
Km_ugt2b7 <- 234
Vmax_2b6 <- 49
Km_2b6 <- 235
Vmax_3a4 <- 726
Km_3a4 <- 808
GFR <- 7.2 # L/hr
Peff <- 0.0258 / 60 * 10000
fu_gut <- 0.618
fu_hep <- 0.52
CbCp <- 0.76

CLint_2b6_ul <- Vmax_2b6/Km_2b6
CLint_3a4_ul <- Vmax_3a4/Km_3a4
CLint_other_ul <- Vmax_ugt2b7/Km_ugt2b7 

EC50_3a4_uM <- 27
Emax_3a4 <- 5.39

# EC50_3a4_uM <- 36
# Emax_3a4 <- 11

data

param_list <- list(
  MW = MW,
  logP = logP,
  pKa = pKa,
  fu = fu,
  fu_gut = fu_gut,
  fu_hep = fu_hep,
  CLint_other_ul = CLint_other_ul,
  CLint_2b6_ul = CLint_2b6_ul,
  CLint_3a4_ul = CLint_3a4_ul,
  CLint_3a4_intestine = CLint_3a4_ul / 155 * 50,
  Fa = absorption_Fa(Peff),
  Ka = absorption_ka(Peff),
  CLrenal = GFR * GFRf,
  EC50_3a4_uM = EC50_3a4_uM,
  Emax_3a4 = Emax_3a4,
  CbCp = CbCp,
  Km_3a4 = Km_3a4
)

##!!! CLint_intestine 부분 정리해야됨

param_list_distribution <- Kpcoeffs(logP, pKa, fu, BP=CbCp, type = 2, pred = "R&R") 

param_list_all <- c(param_list, param_list_distribution)
param_list_all

mod <- param(mod, param_list_all)

# Default simulation scenario
amt <- 600       #input(Simulation)
ii <- 12     #input(Simulation)
addl <- 0    #input(Simulation)
start_time <- 0    #input(Simulation)


simdata <- mod %>%
    ev(amt = amt, ii = ii, addl = addl) %>%
    mrgsim(end = 100, maxsteps = 1000000) %>%
    mutate(Cp_ul = Cp/1000)
simdata %>%
  ggplot(aes(x = time, y = Cp_ul)) +
  geom_line() +
  theme_bw()
plot(data)
head(data)
colnames(data)
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
