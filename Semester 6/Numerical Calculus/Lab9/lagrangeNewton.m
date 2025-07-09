function N = lagrangeNewton(x0, f0, x)
  dd_table = divided_differences_single(x0, f0);
  firstLineDD_Table = dd_table(1, :);
  N = zeros(size(x));
  for k = 1 : length(x)
  p = 1;
  for i = 1 : length(x0)
    N(k) = N(k) + firstLineDD_Table(i) * p;
    p = p * (x(k) - x0(i));
  endfor
endfor
end
