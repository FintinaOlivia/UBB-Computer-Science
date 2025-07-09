#1. Let f : (-1, infinity) -> |R be defined by f(x) = 1 / (1 + x)

#a) Find the divided differences table of f at the simple nodes x0 = 0, x1 = 1, x2 = 2

x = [0, 1, 2];
f = (1 ./ ( 1 + x ));

dd_table = divided_differences_single(x, f)


#b) Find the divided differences table of f at the double nodes x0 = 0, x1 = 1, x2 = 2;

x = [0, 1, 2];
f = (1 ./ ( 1 + x ));
df = (-1 ./ (1 + x).^2);

dd_table = divided_differences_double(x, f, df)


#c) Repeat parts a) and b) at 11 equidistant nodes on the interval [1,2].
x = 1 : 0.1 : 2;
f = (1 ./ ( 1 + x ));
dd_table = divided_differences_single(x, f);

x = 1 : 0.1 : 2;
f = (1 ./ ( 1 + x ));
df = (-1 ./ (1 + x).^2);
dd_table = divided_differences_double(x, f, df)



#2. The following data is gathered:
# x -2 -1  0  1  2  3  4
# f -5  1  1  1  7  25  60

#a) Construct the divided differences table of the data
x = [-2, -1, 0, 1, 2, 3, 4];
f = [-5, 1, 1, 1, 7, 25, 60];
dd_table = divided_differences_single(x, y)


#b) Find the forward differences table of the data
x = [-2, -1, 0, 1, 2, 3, 4];
f = [-5, 1, 1, 1, 7, 25, 60];
fd_table = forward_diff_table(f)


#c) Find the backward differences table of the data
x = [-2, -1, 0, 1, 2, 3, 4];
f = [-5, 1, 1, 1, 7, 25, 60];
bd_table = backward_diff_table(f)



#r
