###------Sampling Distributions------
######################################
par(mfrow=c(2,2))
x <- seq(0,10,by=0.01)
curve(dexp(x,rate=0.5),0,10,main=expression(paste("Exponential ", lambda, "= 0.5")),lwd=2,col="red")
curve(dexp(x,rate=2),0,10,main=expression(paste("Exponential ", lambda, "= 2")),lwd=2,col="red")
curve(dnorm(x,mean=5,sd=2),0,10,main=expression(paste("Normal ", mu, "= 5, ", sigma, "= 2")), lwd=2,col="red")
curve(dnorm(x,mean=5,sd=0.5),0,10,main=expression(paste("Normal ", mu, "= 5, ", sigma, "= 0.5")),lwd=2,col="red")

t <- seq(0,10,by=1)
n <- 10
plot(t,dbinom(t,size=n,prob=0.2),main=expression(paste("Binomial ", "n = 10, p=0.2")), type="h",lwd=2,col="blue")
plot(t,dbinom(t,size=n,prob=0.8),main=expression(paste("Binomial ", "n = 10, p=0.8")),type="h",lwd=2,col="blue")
plot(t,dpois(t,0.5),type="h",main=expression(paste("Poisson ", lambda, "= 0.5")), lwd=2,col="blue")
plot(t,dpois(t,2),type="h",main=expression(paste("Poisson ", lambda, "= 2")), lwd=2,col="blue")


# Exponential Distribution CLT
x <- seq(0,10,by=0.01)
curve(dexp(x,rate=1),0,10,main=expression(paste("Exponential ", lambda, "= 1")),lwd=2,col="blue")
par(mfrow=c(2,2))

# Simulations
n.sim <- 500
n <- 1
xbar <- rep(0,n)

lambda <- 1
mu <- 1/lambda
sigma <- 1/(lambda*sqrt(n))

for(i in 1:n.sim){sample <- rexp(n,rate=lambda)
	xbar[i] <- mean(sample)
	}

hist(xbar,prob=TRUE)
x <- seq(0,10,by=0.01)
curve(dexp(x,rate=1),0,10,add=TRUE,lwd=2,col="blue")
curve(dnorm(x,mean=mu,sd=sigma),0,5,add=TRUE,lwd=2,col="red")


# Binomial Distribution CLT
par(mfrow=c(2,2))
t <- seq(0,10,by=1)
plot(t,dbinom(t,size=10,prob=0.2),type="h",lwd=2,col="blue")
curve(dnorm(x,mean=10*0.2,sd=sqrt(10*0.2*0.8)),0,10,add=TRUE,lwd=2,col="red")


# Simulations
n.sim <- 500
n <- 500

p <- 0.2
mu <- n*p
sigma <- sqrt(n*p*(1-p))

sample <- rbinom(n.sim,size=n,prob=0.2) 
hist(sample,prob=TRUE)
x <- seq(0,10,by=0.01)
curve(dnorm(x,mean=mu,sd=sigma),0,n,add=TRUE,lwd=2,col="red")

