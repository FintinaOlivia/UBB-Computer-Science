n = 5;

A = 5*eye(n) - diag(ones(n-1, 1), 1) - diag(ones(n-1, 1), -1);
b = [4, 3*ones(1, n-2), 4].';

x0 = zeros(1,n);
err = 10^(-5);
maxnit = 1000;

#[x,nit] = jacobi(A,b,x0,err,maxnit)

x0 = zeros(1,n);
[y,mit] = gauss_seidel(A,b,x0,err,maxnit)
