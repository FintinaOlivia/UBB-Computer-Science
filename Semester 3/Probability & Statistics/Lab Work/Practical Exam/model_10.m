# model 10
% A food store owner receives 1-liter water bottles from two suppliers.
% After some complaints from customers, he wants to check the accuracy
% of the weights of 1-liter water bottles. He finds the following
% weights(the two populations are approximately normally distributed):

%            !                            Heat loss                            !
% Supplier A ! 1021 980 1017 988 1005 998 1014 985 995 1004 1030 1015 995 1023 !
% Supplier B ! 1070 970 993 1013 1006 1002 1014 997 1002 1010 975              !
% -----------------------------------------------------------------------------

% a. At the 5% significance level, do the population variances seem to differ?

% data sample
x_A = [1021, 980, 1017, 988, 1005, 998, 1014, 985, 995, 1004, 1030, 1015, 995, 1023]
x_B = [1070, 970, 993, 1013, 1006, 1002, 1014, 997, 1002, 1010, 975]

% size of data sample
n1 = length(x_A)
n2 = length(x_B)

% alpha is the significance level
alpha = 0.05;

%a
fprintf("a)");

% H0 - the null hypothesis
% H0: sigma_A^2 = sigma_B^2  (the variances of the two populations are equal)
% H1 - the research hypothesis
% H1: sigma_A^2 != sigma_B^2 (the variances of the two populations seem to differ)
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

[H, P, CI, stats] = vartest2(x_A, x_B,"alpha", alpha);


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
