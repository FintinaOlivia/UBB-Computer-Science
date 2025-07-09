function [x,nit]=sor(A,b,orp,x0,err,maxnit)
  n = length(b);
  M = diag(diag(A)) / orp - (tril(A) - diag(diag(A)); # M = D/orp - L
  N = ((1 - orp)/orp*D) + (triu(A) - diag(diag(A)); # N = (1-w/orp)*D + U

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
