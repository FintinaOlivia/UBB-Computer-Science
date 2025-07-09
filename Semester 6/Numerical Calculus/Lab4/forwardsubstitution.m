function x=forwardsubstitution(L, b)
  [n, m] = size(L);
  x = zeros(m, 1);

  for i=1:n
    x(i) = (b(i) - L(i, 1:i-1) * x(1:i-1)) / L(i, i);
  endfor
endfunction
