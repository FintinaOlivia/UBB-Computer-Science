#1. Let f : (-1, infinity) -> |R be defined by f(x) = 1 / (1 + x)

#a) Find the divided differences table of f at the simple nodes x0 = 0, x1 = 1, x2 = 2;

#x = [0, 1, 2];
#f = (1 ./ ( 1 + x ));

#dd_table = divided_differences_single(x, f)


#b) Find the divided differences table of f at the double nodes x0 = 0, x1 = 1, x2 = 2;
#x = [0, 1, 2];
#f = (1 ./ ( 1 + x ));
#df = (-1 ./ (1 + x).^2);
#df = diff(f,x);

#[z,t] = divided_differences_double(x, f, df)

#c) Repeat parts a) and b) at 11 equidistant nodes on the interval [1,2].

x = linspace(1,2,11);
f = (1 ./ ( 1 + x ));
dd_table = divided_differences_single(x, f);

f = (1 ./ ( 1 + x ));
df = (-1 ./ (1 + x).^2);
[z,t] = divided_differences_double(x, f, df);
disp(z)
disp(t)

