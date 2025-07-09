function bi = barycentric(nodes,f_nodes,xi)
  bi=zeros(size(xi));
  n=length(nodes);
  m=length(xi);
  li=ones(1,n);

  for i = 1:n
       wi(i)= 1 / (prod(nodes(i)-nodes([1:i-1,i+1:n])));
  endfor

  for i = 1:m
    ui(i) = prod(xi(i) - nodes([1:n]));
    bi(i)= ui(i)*wi ./ (xi(i) - nodes([1:n]))*f_nodes';
  endfor
 endfunction


