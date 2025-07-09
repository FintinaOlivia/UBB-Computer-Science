function [x,nit]=gauss_seidel(A,b,x0,err,maxnit)
  n = length(b);
  N = -(triu(A) - diag(diag(A))); # N = U
  M = A + N;

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
