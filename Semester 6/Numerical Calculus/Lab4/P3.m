n = 9;
A = 5*eye(n) - diag(ones(n-1, 1), 1) - diag(ones(n-1, 1), -1);
A = A - diag(ones(n-3, 1), 3) - diag(ones(n-3, 1), -3)

b = [3, 2, 2, 1, zeros(1, n-8), 1, 2, 2, 3].'

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
