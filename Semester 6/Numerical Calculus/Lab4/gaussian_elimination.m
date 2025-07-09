function x = gaussian_elimination(A, b)
    n = length(b);
    augmented = [A b];

    for k = 1:n-1
        [max_value, max_row] = max(abs(augmented(k:n, k)));
        max_row = max_row + k - 1;

        if max_row ~= k
            aux = augmented(k, :);
            augmented(k, :) = augmented(max_row, :);
            augmented(max_row, :) = aux;
        endif

        for i = k+1:n
            m = augmented(i, k) / augmented(k, k);
            augmented(i, k:end) = augmented(i, k:end) - m * augmented(k, k:end);
        endfor
    endfor

    U = augmented(:, 1:end-1);
    b_new = augmented(:, end);

    x = backsubstitution(U, b_new);
    #x = x';
end
