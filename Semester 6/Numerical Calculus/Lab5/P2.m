A = [10 7 8 7;
     7 5 6 5;
     8 6 10 9;
     7 5 9 10];

b = [32 23 33 31]';

# a)

x = A\b;

# b)
b_pert = [ 32.1 22.9 33.1 30.9 ]';
x_pert = A\b_pert;

errb = norm(x-x_pert, inf)/norm(x,inf);
errb_pert = norm(b-b_pert, inf)/norm(b, inf);

# c)
A_pert = [ 10 7 8.1 7.2;
          7.8 5.04 6 5;
          8 5.98 9.89 9;
          6.99 4.99 9 9.98];
x_Apert = (A_pert\b);

errc= norm(x-x_Apert, inf) / norm(x, inf);
errc_pert = norm(A-A_pert, inf) / norm(A,inf);

# d)
cond(A)

