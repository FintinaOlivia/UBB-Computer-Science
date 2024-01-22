%b. At the same significance level does it seem that on average, steel pipes
% lose more heat than glass pipes?

% data sample
x_steel = [4.6, 0.7, 4.2, 1.9, 4.8, 6.1, 4.7, 5.5, 5.4]
x_glass = [2.5, 1.3, 2.0, 1.8, 2.7, 3.2, 3.0, 3.5, 3.4]
% size of data sample
n1 = length(x_steel)
n2 = length(x_glass)

% alpha is the significance level
alpha = 0.05;

% H0 - null hypothesis
% H0: steel pipes lose the same amount of heats than glass pipes
% H0: miu_steel = miu_glass
% H1 - the research hypothesis
% H1: steel pipes lose more heat than glass pipes
% H1: miu_steel > miu_glass
% => we perform a right-tailed test
fprintf("We perform a right-tailed test for the difference of two population means\n");

% We want to perform a test for the difference of two population means:
% since from a) we got that the devations differ, so enter the third case:
% ttest2 with TT in T(n)

[H,P,CI,statistics] = ttest2(x_steel, x_glass, 'alpha', alpha, 'tail', 'right');

fprintf('\n H is %d', H)
if H == 1
  fprintf('\nSo the null hypothesis is rejected,\n');
  fprintf('i.e. the data suggests that steel pipes lose more heat than glass pipes.\n');
else
  fprintf('\nSo the null hypothesis is not rejected,\n');
  fprintf('i.e. the data suggests that steel pipes do not lose more heat than glass pipes.\n');
end


% building the rejection region
% RR = (tt_{1-alpha},inf) since it's a right-tailed test
% tt_alpha is the quantile for the T(n) distribution

% compute the sample variances
var1 = var(x_steel);
var2 = var(x_glass);

% compute c and n
c = (var1/n1)/(var1/n1+var2/n2);
n = 1/((c^2/(n1-1) + (1-c)^2/(n2-1)));

tt_alpha = tinv(1-alpha, n)     # critical value obtained
RR = [tt_alpha, inf]% vector with 2 positions

% print ZVAL, P and RR on the screen
fprintf('\nThe rejection region is (%4.4f, %4.4f)\n', RR);
fprintf('The value of the test statistic z is %4.4f\n', statistics.tstat);
fprintf('The P-value of the test is %4.4f\n', P);
