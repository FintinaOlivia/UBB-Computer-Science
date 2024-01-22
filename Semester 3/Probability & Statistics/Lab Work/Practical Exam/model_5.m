# model 5
% To reach the maximum efficiency in performing an assembling operation
% in a manufacturing plant, new employees are required to take a 1-month training
% corse. A new method was suggested, and the maager wants to compare the new
% method with the standard one, by looking at the lengths of time required for
% employees to assemble a certain device. They are given below (and assumed
% normally distributed):

%          !       Assembling times        !
% Standard ! 46 37 39 48 47 44 35 31 44 37 !
% New      ! 35 33 31 35 34 30 27 32 31 31 !
% -------------------------------------------

% a. At the 5% significance level, do the population variances seem to differ?
x_standard = [46, 37, 39, 48, 47, 44, 35, 31, 44, 37]
x_new = [35, 33, 31, 35, 34, 30, 27, 32, 31, 31]

n1 = length(x_standard)
n2 = length(x_new)
% H0 - null hypothesis
% H0: The population variances are equal
% H0: (sigma_standard)^2 = (sigma_new)^2
% H1 - the research hypothesis
% H1: The population variances seem to differ
% H1: (sigma_standard)^2 != (sigma_new)^2
% => we perform a two-tailed test
fprintf("We perform a two-tailed test for the ratio of two population variances\n");

% we want to perform a test for the ratio of two population variances
% => vartest2 as TT in F(n_1-1, n_2-1)


% vartest2 -> test for the ratio of two population variances
% INPUT : x1 = the first data sample
%         x2 = the second data sample
%         alpha = the significance level
% OUTPUT: H = indicator which tells us if we reject or do not reject H_0
%         P = critical value of the test (p-value)
%         CI = confidence interval
%         statistics = TS_0 TS when theta = theta0. If TS_0 is in RR => reject H0.

[H, P, CI, stats] = vartest2(x_standard, x_new,"alpha", alpha);


% result of the test, h = 0, if H0 is NOT rejected,
% h = 1, if H0 IS rejected
fprintf('\n H is %d', H)
if H == 1
  fprintf('\n So the null hypothesis is rejected, \n')
  fprintf('i.e the variances of the two populations seem to differ.\n')
else
  fprintf('\nSo the null hypothesis is not rejected,\n')
  fprintf('i.e. the variances of the two populations are equal.\n')
end


% building the rejection region
% RR = (-inf, tt_{alpha/2}) U (tt_{1-alpha/2},inf) since it's a two-tailed test
% tt_alpha is the quantile for the F(n_1-1, n2_-1) distribution

tt_alpha1 = finv(alpha/2, n1-1, n2-1)
tt_alpha2 = finv(1-alpha/2, n1-1, n2-1)
RR1 = [-inf, tt_alpha1]
RR2 = [tt_alpha2, inf] % vector with 2 positions

% print ZVAL, P and RR on the screen
fprintf('\nThe rejection region is (%4.4f, %4.4f) U (%4.4f, %4.4f)\n', RR1, RR2);
fprintf('The value of the test statistic z is %4.4f\n', stats.fstat);
fprintf('The P-value of the test is %4.4f\n\n', P);
