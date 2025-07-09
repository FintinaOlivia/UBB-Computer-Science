A = [2 1 -1 -2;
     4 4 1 3;
     -6 -1 10 10;
     -2 1 8 4];

b = [2 4 -5 1];
b = b';

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
