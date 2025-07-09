clear

pkg load symbolic

syms x

#a) Graph on the same set of axes the function e^x
# and its Taylor polynomials of degrees 1, 2, 3 and 4, for
# x ∈ [−3, 3];

f = exp(x);
# T1 = taylor(f,x,0, 'Order', 2);
T1 = taylor(f, x, 'Order', 2);
T2 = taylor(f, x, 'Order', 3);
T3 = taylor(f, x, 'Order', 4);
T4 = taylor(f, x, 'Order', 5);

f_handle = matlabFunction(f);
T1_handle = matlabFunction(T1);
T2_handle = matlabFunction(T2);
T3_handle = matlabFunction(T3);
T4_handle = matlabFunction(T4);

x_vals = [ -3 : 0.1 : 3 ];
#alternative: linspace(-3,3,100)
#xlim([-3,3])
figure(1)

hold on
plot(x_vals, f_handle(x_vals), 'k', 'LineWidth', 2, 'DisplayName', 'e^x')
plot(x_vals, T1_handle(x_vals), 'r--', 'DisplayName', 'Degree 1')
plot(x_vals, T2_handle(x_vals), 'g--', 'DisplayName', 'Degree 2')
plot(x_vals, T3_handle(x_vals), 'b--', 'DisplayName', 'Degree 3')
plot(x_vals, T4_handle(x_vals), 'm--', 'DisplayName', 'Degree 4')
legend()
hold off

#b) Approximate e with 6 correct decimals

approx = vpa(subs(taylor(f, x, 0, 'order', 10), 1),6);
disp(approx)
#printf("The value of e is approximately %.10f with the error %.10f", approx,
# approx - double(subs(f, 1)));

