# model 10 b
% b. At the same significancce level, on average, does Supplier A seem to be
% more reliable?

% data sample
x_A = [1021, 980, 1017, 988, 1005, 998, 1014, 985, 995, 1004, 1030, 1015, 995, 1023]
x_B = [1070, 970, 993, 1013, 1006, 1002, 1014, 997, 1002, 1010, 975]

% size of data sample
n1 = length(x_A)
n2 = length(x_B)

% alpha is the significance level
alpha = 0.05;

%b
fprintf("b)");

% on average means miu

% H0 - the null hypothesis
% H0: Supplier A does not seem to be more reliable than Supplier B
% H0: miu_A = miu_B
% H1 - the research hypothesis
% H1: Supplier A seems to be more reliable
% H1: miu_A > miu_B
% => we perform a right-tailed test
fprintf("We perform a right-tailed test for the difference of two population means,\n");



% we want to perform a test for the difference of two population means,
% We don't know sigma and we know they are equal so it's the second case
% => ttest2 as TT in T(n_1+n_2-2)


% ttest2 -> test for the mean of a population(theta=miu), the case where sigma is unknown
% INPUT : x1 = the first data sample
%         x2 = the second data sample
%         alpha = the significance level
%         tail = right
% OUTPUT: H = indicator which tells us if we reject or do not reject H_0
%         P = critical value of the test (p-value)
%         CI = confidence interval
%         statistics = TS_0 TS when theta = theta0. If TS_0 is in RR => reject H0.
[H,P,CI,statistics] = ttest2(x_A, x_B, 'alpha', alpha, 'tail', 'right');
% result of the test, h = 0, if H0 is NOT rejected,
% h = 1, if H0 IS rejected
fprintf('\n H is %d', H)
if H == 1
    fprintf('\nSo the null hypothesis is rejected,\n')
    fprintf('i.e. the data suggests that the supplier A seems to be more reliable.\n')
else
    fprintf('\nSo the null hypothesis is not rejected,\n')
    fprintf('i.e. the data suggests that the supplier A does not seem to be more reliable.\n')
end


% building the rejection region
% RR = (-inf, tt_{alpha/2}) U (tt_{1-alpha/2},inf) since it's a two-tailed test
% tt_alpha is the quantile for the F(n_1-1, n2_-1) distribution

tt_alpha = tinv(1-alpha, n1+n2-2)
RR = [tt_alpha, inf]% vector with 2 positions

% print ZVAL, P and RR on the screen
fprintf('\nThe rejection region is (%4.4f, %4.4f)\n', RR);
fprintf('The value of the test statistic z is %4.4f\n', statistics.tstat);
fprintf('The P-value of the test is %e\n', P);
