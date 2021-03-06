library(XBCF)
library(nnet)

## 1. data generation

## generate a matrix of covariates
n = 2000
x1 = rnorm(n)
x2 = sample(1:2,n,replace=TRUE)
x3 = sample(1:3,n,replace=TRUE,prob = c(0.3,0.4,0.3))
x4 = rnorm(n)
x5 = rnorm(n)
x = cbind(x1,x4,x5,x2,as.factor(x3))

## define prognostic function
linear = TRUE
mu = function(x){
  lev = c(2,-1,-4)
  if (linear) {result = 1 + lev[x[,5]] + x[,1]*x[,3]
  } else {result = -6 + lev[x[,5]] + 6*abs(x[,3] - 1)}
  return(result)
}

## generate treatment effects
homogeneous = FALSE
if(homogeneous) {tau = rep(3,n)
} else {tau =  1 + 2*x[,2]*x[,4]}

## define the propensity score function
pi = 0.8*pnorm(3*mu(x)/sd(mu(x))-0.5*x[,1],0,1) + 0.05 + 0.1*runif(n)

## generate treatment assignment scheme
z = rbinom(n,1,pi)

## generate response variable
Ey = mu(x) + tau*z
sig = 0.5*sd(Ey)
y = Ey + sig*rnorm(n)


## 2. treatment effect estimation

## scale response variable
meany = mean(y)
y = y - mean(y)
sdy = sd(y)
y = y/sdy

## compute propensity score estimates
fitz = nnet(z ~ .,data = x,size = 3,rang = 0.1, maxit = 1000,abstol = 1.0e-8, decay = 5e-2)
pihat = fitz$fitted.values

## bind the column with propensity scores to our data (to use this matrix as a )
x1 <- cbind(pihat,x)

## XBCF parameters
burnin = 15           # number of burnin sweeps
sweeps = 40           # total number of sweeps through data
treesmu = 30          # number of trees in forest for prognostic term 
treestau = 10         # number of trees in forest for treatment term
max_depth = 250       # maximum depth of a tree
Nmin = 1              # minimum node size
num_cutpoints = 20    # number of adaptive cutpoints considered at each split for cont variables
mtry_pr = ncol(x1)    # number of variables considered at each split in trees for prognostic term
mtry_trt = ncol(x)    # number of variables considered at each split in trees for treatment term
p_cat = 2             # number of categorical regressors

tau1 = 0.6*var(y)/treesmu   # prior leaf variance for trees for prognostic term
tau2 = 0.1*var(y)/treestau  # prior leaf variance for trees for treatment term

## run xbcf
fit_xbcf = XBCF(y, x1, x, z, num_sweeps = sweeps, burnin = burnin, 
                max_depth = max_depth, Nmin = Nmin, num_cutpoints = num_cutpoints, no_split_penality = "Auto", 
                mtry_pr = mtry_pr, mtry_trt = mtry_trt, p_categorical_pr = p_cat, p_categorical_trt = p_cat, 
                num_trees_pr = treesmu,  tau_pr = tau1, num_trees_trt = treestau, tau_trt = tau2)

## obtain the treatment effect estimates from the fit
th_xbcf = fit_xbcf$tauhats * sdy
b_xbcf = fit_xbcf$b_draws
seq <- (burnin + 1):sweeps
for (kk in seq) {
  th_xbcf[, kk] = th_xbcf[, kk] * (b_xbcf[kk, 2] - b_xbcf[kk, 1])
}
tauhats_xbcf = rowMeans(th_xbcf[, (burnin + 1):sweeps])

## compute rmse
rmse.cate.x = sqrt(mean((tau - tauhats_xbcf)^2))
rmse.ate.x = sqrt(mean((mean(tau)-mean(tauhats_xbcf))^2))
rmse.cate.x
rmse.ate.x

## plot the estimates
plot(tau,tauhats_xbcf)
abline(0,1,col='red')
