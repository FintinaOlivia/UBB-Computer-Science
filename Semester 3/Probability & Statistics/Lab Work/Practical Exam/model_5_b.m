#model 5 b
% b. Find a 95% confidence interval for the difference of the average
% assembling times.

% data sample
x_standard = [46, 37, 39, 48, 47, 44, 35, 31, 44, 37]
x_new = [35, 33, 31, 35, 34, 30, 27, 32, 31, 31]

% data size
n1 = length(x_standard)
n2 = length(x_new)

% alpha = 0.05
alpha = 0.05

% For the difference of two population means
% We don't know sigma and we know they are not equal so it's the third case

% compute the sample variances
var1 = var(x_standard);
var2 = var(x_new);

% compute the means
xbar1 = mean(x_standard);
xbar2 = mean(x_new);

% compute c and n
c = (var1/n1)/(var1/n1+var2/n2);
n = 1/((c^2/(n1-1) + (1-c)^2/(n2-1)));

% and now the quantiles referring to the T(n) distribution
t1 = tinv(1-alpha/2, n);

% compute the limits of the confidence interval
limit1 = xbar1 - xbar2 - t1*sqrt((var1/n1)+(var2/n2));
limit2 = xbar1 - xbar2 + t1*sqrt((var1/n1)+(var2/n2));

fprintf('The confidence interval for the difference of true means is: (%6.3f,%6.3f)\n',limit1, limit2);
