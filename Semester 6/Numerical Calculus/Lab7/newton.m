function N = newton(x0,f0, x)
  n = length(x0);
  m = length(x);

  N = zeros(size(x));

  dd = divdiff(x0,f0);
  frow = dd(1,:);

  for j = 1 : length(x)
    p = 1;
    for i = 1 : length(x0)
      N(j) = N(j) + frow(i) *  p;
      p = p * (x(j) - x0(i));
    endfor
  endfor

endfunction
