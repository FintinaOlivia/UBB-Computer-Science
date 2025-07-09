#Formula 5.8/ Lecture 2

function fd_table = forward_diff_table(f_values)
    pkg load symbolic
    n = length(f_values);
    fd_table = zeros(n, n);
    fd_table(:, 1) = f_values(:);

    for j = 2:n
        for i = 1:(n-j+1)
            fd_table(i, j) = fd_table(i+1, j-1) - fd_table(i, j-1);
        end
    end
end
