function [x,nit]=jacobi(A,b,x0,err,maxnit)
  n = length(b);
  M = diag(diag(A)); # M = D
  N = M - A; # N = L + U

  # because it's -L and -U, and their addition is equal to N
  #therefore we flip it

  C=inv(M)*b;
  T=inv(M)*N;
  x0 = x0';

  for k=1:maxnit
    x = T * x0 + C;
    if norm(x - x0, inf) < ((1 -  norm(T,inf))/ norm(T,inf)) * err
      nit = k;
      return
    endif
    x0 = x;
  endfor
  error("Too many iterations or too difficult to compute");
end
