function bi = doLagrangeBar(nodes, f_nodes, xi)
  fi = zeros(size(xi));
  n = length(nodes);
  m = length(xi);
  li= ones(size(nodes));
  w = ones(size(nodes));
  for j = 1 : m
    u = prod(xi(j) - nodes);
    for i = 1 : n
      w(i) = 1 / prod(nodes(i) - nodes([1:i-1,i+1:n]));
    endfor
    fi(j) = u * w(j) * f_nodes(j);
  endfor
end

