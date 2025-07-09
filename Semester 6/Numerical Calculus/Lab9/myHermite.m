function H = myHermite(x0, f0, d0, x)
  dd_table = divided_differences_double(x0, f0, d0);
  firstLineDD_Table = dd_table(1, :);
  x0 = repelem(x0, 2);
  H = zeros(size(x));
  for k = 1 : length(x)
    p = 1;
    for i = 1 : length(x0)
      H(k) = H(k) + firstLineDD_Table(i) * p;
      p = p * (x(k) - x0(i));
    endfor
  endfor
end

