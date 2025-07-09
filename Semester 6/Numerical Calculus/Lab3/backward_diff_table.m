#Formula 5.8/ Lecture 2

function bd_table = backward_diff_table(f_values)
    pkg load symbolic
    n = length(f_values);
    bd_table = zeros(n, n);
    bd_table(:, 1) = f_values(:);

    for j = 2:n
        for i = n:-1:j
            bd_table(i, j) = bd_table(i, j-1) - bd_table(i-1, j-1);
        end
    end
end
