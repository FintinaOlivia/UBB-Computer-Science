# a)
n = 10;
A = 5*eye(n) - diag(ones(n-1, 1), 1) - diag(ones(n-1, 1), -1);
A = A - diag(ones(n-3, 1), 3) - diag(ones(n-3, 1), -3)

b = [3, 2, 2, 1, zeros(1, n-8), 1, 2, 2, 3].'

x0 = zeros(1,n);
err = 10^(-5);
maxnit = 1000;



# b)
n = 1000
A = 5*eye(n) - diag(ones(n-1, 1), 1) - diag(ones(n-1, 1), -1);
A = A - diag(ones(n-3, 1), 3) - diag(ones(n-3, 1), -3)

b = [3, 2, 2, 1, zeros(1, n-8), 1, 2, 2, 3].'

x0 = zeros(1,n);
err = 10^(-5);
maxnit = 1000;
