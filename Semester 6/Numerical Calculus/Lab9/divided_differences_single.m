#f[x0, x1, . . . , xn] = (f[x1, x2, . . . , xn] − f[x0, x1, . . . , xn−1])/(xn − x0)
# Formula 5.3, LEcture 1

function dd_table = divided_differences_single(x, f)
    pkg load symbolic
    x = vpa(x);
    f = vpa(f);

    n = length(x);
    dd_table = sym(zeros(n, n));
    dd_table(:, 1) = f';

    for j = 2:n
        dd_table(1:n-j+1,j) = (dd_table(2:n-j+2,j-1) - dd_table(1:n-j+1, j-1)) ./ (x(j:n) - x(1:n-j+1))';
    end

    dd_table = vpa(dd_table, 5);
end
