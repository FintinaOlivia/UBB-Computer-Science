function dd_table = divided_differences_double(x, f, df)
    % This function computes the divided differences table for given nodes x
    % and function values f, automatically handling double nodes.
    % x - vector of unique nodes
    % f - vector of function values at nodes
    % dd_table - the divided differences table

    fdouble = repelem(f, 2);
    dfdouble = repelem(df, 2);
    xdouble = repelem(x,2);

    n = length(x) * 2;

    dd_table = zeros(n, n);
    dd_table(:, 1) = fdouble(:);

    for i = 1:2:n
        dd_table(i, 2) = dfdouble(i);
    end

    for i = 2:2:n-1
        dd_table(i, 2) = (dd_table(i+1, 1) - dd_table(i, 1)) / (xdouble(i+1) - xdouble(i));
    end

    for j = 3:n
        for i = 1:(n-j+1)
            dd_table(i, j) = (dd_table(i+1, j-1) - dd_table(i, j-1)) / (xdouble(i+j-1) - xdouble(i));
        end
    end


end
