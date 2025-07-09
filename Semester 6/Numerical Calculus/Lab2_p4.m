#4. Use formula (6) to approximate √3 999 with 10 correct decimals

# √3 999 = 10 * √3 999/1000 = 10 * √3 (1 - 1/1000)

syms x
f = 10 * nthroot(1-x, 3)
T = taylor(f, x, 'Order', 101);
T_handle = matlabFunction(T);
x = 1/1000;

approx = T_handle(x);
real_solution = cbrt(999)

printf("The value of cbrt(999) is approximately %.10f with the error %.10f",
    approx, approx-real_solution);


#vpa vs double -> vpa gives a precise number of digits, double provides all of thems
