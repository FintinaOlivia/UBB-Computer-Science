function [z,t] = divided_differences_double(x, f, df)
    pkg load symbolic

    z = repelem(x,2);
    lz = length(z);
    t = zeros(lz);
    t(:,1) = repelem(f,2)';

    t(1:2:lz-1,2) = df';
    t(2:2:lz-2,2) = (diff(f) ./ diff(x))';
    for j=3:lz
      t(1:lz-j+1,j) = (t(2:lz-j+2,j-1) - t(1:lz-j+1, j-1)) ./ (z(j:lz) - z(1:lz-j+1))';
    end
end
