syms x
#a) Graph on the same set of axes the function sin x and its Taylor polynomials
#of degrees 3 and 5, for x ∈ [−π, π];

f = sin(x)

T1 = taylor(f, x, 'Order', 4);
T2 = taylor(f, x, 'Order', 6);

f_handle = matlabFunction(f);
T1_handle = matlabFunction(T1);
T2_handle = matlabFunction(T2);

x_vals = [ -pi : 0.1*pi : pi ];
figure(2)

hold on
plot(x_vals, f_handle(x_vals), 'k', 'LineWidth', 2, 'DisplayName', 'sin(x)')
plot(x_vals, T1_handle(x_vals), 'r--', 'DisplayName', 'Degree 3')
plot(x_vals, T2_handle(x_vals), 'g--', 'DisplayName', 'Degree 5')
legend()
hold off

#b)Approximate sin(π/5) with 5 correct decimals;
T = taylor(f, x, 'Order', 101);
T_handle = matlabFunction(T);
x = pi/5;
approx = T_handle(x);

printf("The value of sin(π/5) is approximately %.10f with the error %.10f",
    approx, approx - double(subs(f, pi/5)));

#What happens for x = 10π/3 ? Explain the phenomenon and find a solution.
T = taylor(f, x, 'Order', 101);
T_handle = matlabFunction(T);
x = 10*pi/3;
approx = T_handle(x);

printf("The value of sin(10π/3) is approximately %.10f with the error %.10f",
    approx, approx - double(subs(f, 10*pi/3)));


