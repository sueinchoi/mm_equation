library(tidyverse)
library(readxl)

# Read in data
data <- read_excel("Value.xlsx") %>%
    as.data.frame()
data
# Create a function to calculate the absorption


absorption_Peff <- function(caco_2) {
    10^(0.6795*log10(caco_2) - 0.3746)
}

absorption_ka <- function(Peff) {
    Peff
}

absorption_Fa <- function(Peff) {
    1 - (1 + 0.54*Peff)^(-7)
}
data
absorption_Fg <- function(CLint, Peff, fu_gut = 1){
    CLint_pmol <- CLint / data[data$Name == "CYP3A_gut", "Value"]
    CL_perm <- Peff * data[data$Name == "A", "Value"]/1000*60*60*10^(-4)
    Qgut = CL_perm * data[data$Name == "Qent", "Value"]/ (CL_perm + data[data$Name == "Qent", "Value"])
    Qgut / (Qgut + fu_gut * CLint_pmol * data[data$Name == "Total CYP3A", "Value"] * 1000 * 60 / 1000 / 1000)
}

# Create function for distribution
source("Kp_calculator/code/CalcKp_Berez.R")
source("Kp_calculator/code/CalcKp_P&T.R")
source("Kp_calculator/code/CalcKp_R&R.R")
source("Kp_calculator/code/getPartitionCoeff.R")

