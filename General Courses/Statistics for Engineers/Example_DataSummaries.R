###----DATA SUMMARIES----
#########################

# Read the data 
data <- read.csv("Data_hist.csv",header=TRUE)

# What is the dimension of the data?
dim(data)

# Can define a "numerical" variable with the column of interest
scores <- data[,1]

# Stem-and-leaf plot
stem(scores, scale=1)

# Construct the histogram
hist(scores)

# you can also add a title and labels if you want
hist(scores,main="Histograms of Scores", ylab="Frequency of Scores", xlab="Scores")


# For questions about how to use this function, you can type
?hist

# For a boxplot you can simple use
boxplot(scores, main="Boxplot od Scores")

# or, if you want an horizontal display
boxplot(scores, main="Boxplot of Scores", horizontal=TRUE)

# Multiple plotting windows
par(mfrow=c(1,2))

hist(scores,main="Histograms of Scores", ylab="Frequency of Scores", xlab="Scores")
boxplot(scores, main="Boxplot of Scores", horizontal=TRUE)

# Numerical summaries
summary(scores)

# Mean and standard deviation
mean(scores)
sd(scores)

# For percentiles
quantile(scores,.25)
quantile(scores,prob=c(.25,.50,.75))
###########################
