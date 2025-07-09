function dd_table = divdiff(x, f)
    n = length(x);
    dd_table = zeros(n, n);
    dd_table(:, 1) = f(:);

    for j = 2:n
        for i = 1:(n-j+1)
            dd_table(i, j) = (dd_table(i+1, j-1) - dd_table(i, j-1)) / (x(i+j-1) - x(i));
        end
    end
end
