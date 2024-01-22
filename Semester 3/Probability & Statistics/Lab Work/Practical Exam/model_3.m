# model 3
% Nickel powders are used in coattings used to shield electronic equipment.
% A random sample is selected, and the sizes of nickel particles in each coating
% are recorded (they are assumed to be approximately normally distributed):

% 3.26, 1.89, 2.42, 2.03, 3.07, 2.95, 1.39, 3.06, 2.46, 3.35, 1.56, 1.79, 1.76, 3.82, 2.42, 2.96

% a. Find a 95% confidence interval for the average size of nicked particles

% significance lvl = 1-confidence lvl, so alpha is 0.05
alpha = 0.05

% sample data
x = [3.26, 1.89, 2.42, 2.03, 3.07, 2.95, 1.39, 3.06, 2.46, 3.35, 1.56, 1.79, ...
     1.76, 3.82, 2.42, 2.96]

% data size
n = length(x)

% compute the mean
xbar = mean(x)

% average size means miu
% sigma is not known and the population is approximately normally distributed
% => second case
sigma = std(x);

% miu in (xbar - sigma/sqrt(n)*t_{1-alpha/2}, xbar - sigma/sqrt(n)*t_{alpha/2}
% where
% t_{1-alpha/2}, t_{alpha/2} are quantiles referring to the T(n-1) distribution

% and now compute the quantiles referring to the T(n-1) distribution
t1 = tinv(1-alpha/2,n-1);
t2 = tinv(alpha/2,n-1);

% now compute the confidence limits
limit1 = xbar - sigma/sqrt(n)*t1;
limit2 = xbar - sigma/sqrt(n)*t2;

fprintf('The confidence interval for the average size of nickel particles is: (%6.3f,%6.3f)\n',limit1,limit2);

