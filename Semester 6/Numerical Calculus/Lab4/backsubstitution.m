function x=backsubstitution(U, b)
  [n, m] = size(U);
  x = zeros(m, 1);

  for i=n:-1:1
    x(i) = (b(i) - U(i, i+1:m) * x(i+1:m)) / U(i, i);
  endfor
endfunction
