# A = [ 5 -1 0 ; -1 5 -1 ; 0 -1 5 ];
n = 7;
A = 5*eye(n) - diag(ones(n-1, 1), 1) - diag(ones(n-1, 1), -1);

# b = [4 3 4];
b = [4, 3*ones(1, n-2), 4].';


disp("QR Factorization")
x_qr = factorization(A, b, 1);
disp(x_qr);
disp("\n")

disp("Cholesky Factorization")
x_chol = factorization(A, b, 2);
disp(x_chol);
disp("\n")

disp("LUP Factorization")
x_lup = factorization(A, b, 3);
disp(x_lup);
disp("\n")

disp("Gaussian elimination with partial pivoting")
x = gaussian_elimination(A, b);
disp(x);
