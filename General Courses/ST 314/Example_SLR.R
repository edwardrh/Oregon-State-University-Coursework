###----EXAMPLE SIMPLE LINEAR REGRESSION--------
###--------------POLYMERS DATA-----------------
###############################################

# Consider the data set "polymers.csv".The response variable y is the amount of suspended 
# solids in a coal cleansing system. Using a quantitative regresor variable x, the pH of the
# cleansing tank is recorded. The cleansing operation involves the use of a polymer. In this
# case three different polymers were used in the experiment. We will fit a simple linear regression
# model to explore the association between the variables pH and amount of solids.
####

# 1) Read the data and look at scatters plot altogether and by groups
data <- read.csv("polymers.csv",header=TRUE)

pH <- data[,1]
solid <- data[,2]

# Scatterplot without distingushing groups
plot(pH,solid,type="p",pch=20, col="blue", main="Scatter Plot", xlab="pH",ylab="Amount of Solids")
cor(pH,solid) # Correlation between the two variables

# Fit the simple linear regression model
slr <- lm(solid ~ pH) 
summary(slr) # coefficients an t-tests
anova(slr)   # ANOVA table

# Confidene intervals for the coefficients
confint(slr, level=0.95)

# Add the regression line in the scatter-plot
plot(pH,solid,type="p",pch=20, col="blue", main="Scatter Plot", xlab="pH",ylab="Amount of Solids")
abline(slr)

# Do calculations by hand
Sx <- sd(pH)
Sy <- sd(solid)
Xbar <- mean(pH)
Ybar <- mean(solid)
r <- cor(pH,solid)

beta1 <- r*Sy/Sx
beta0 <- Ybar-beta1*Xbar

# How to obtain z-scores and t-scores in R?
qt(0.025, 17, lower.tail=FALSE)
qnorm(0.025, mean=0, sd=1, lower.tail = FALSE)

# How to obtain P-values in R?
pt(1.64, 17, lower.tail=FALSE)
pnorm(1.64, mean=0, sd=1, lower.tail=FALSE)

###########################
