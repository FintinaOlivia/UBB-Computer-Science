syms x

#a) Using formula (5), graph on the same set of axes the function ln (1 + x)
#and its Taylor polynomials of degrees 2 and 5, for x ∈ [−0.9, 1];

f = log(1+x)

T1 = taylor(f, x, 'Order', 3);
T2 = taylor(f, x, 'Order', 6);

f_handle = matlabFunction(f);
T1_handle = matlabFunction(T1);
T2_handle = matlabFunction(T2);

x_values = [-0.9:0.1:1];
figure(3)

hold on
plot(x_values, f_handle(x_values), 'k', 'LineWidth', 2, 'DisplayName', 'ln(1+x')
plot(x_values, T1_handle(x_values), 'r--', 'DisplayName', 'Degree 2')
plot(x_values, T2_handle(x_values), 'g--', 'DisplayName', 'Degree 5')
legend()
hold off

#b) How many terms would be necessary in (5) to approximate ln 2 with 5
# correct decimals?

for i = 2 : 15
  T = taylor(f, x, 'Order', 350);
  T_handle = matlabFunction(T);
  x = 1;
  approx = T_handle(x);
  printf("The value of ln(1+x) is approximately %.10f with the error %.10f\n",
    approx, approx - double(subs(f, pi/5)));
end

vpa(log(2),7) #value precision floating point number

#c) Use formula (5) to find a Taylor series expansion for the function ln (1 − x).
T = taylor(f, x, 'Order', 6);
T_neg_x = subs(T, x, -x);
disp(T_neg_x)

#d) Use formula (5) and the one found in part c) to derive
# a Taylor series expansion for the function ln ( 1 + x / 1 − x )

T1 = taylor(f, x, 'Order', 6);
T2 = subs(T1, x, -x);
T_final = T1 - T2;
disp('\nTaylor series expansion for ln((1 + x) / (1 - x)) up to 5th degree:')
disp(T_final)
