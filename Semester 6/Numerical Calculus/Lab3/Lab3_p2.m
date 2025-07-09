#2. The following data is gathered:
# x -2 -1  0  1  2  3  4
# f -5  1  1  1  7  25  60

#a) Construct the divided differences table of the data;
x = [-2:1:4];
f = [-5, 1, 1, 1, 7, 25, 60];
dd_table = divided_differences_single(x, f)


#b) Find the forward differences table of the data;
#x = [-2:1:4];
#f = [-5, 1, 1, 1, 7, 25, 60];
fd_table = forward_diff_table(f)


#c) Find the backward differences table of the data.
#x = [-2:1:4];
#f = [-5, 1, 1, 1, 7, 25, 60];
bd_table = backward_diff_table(f)
