function x=factorization(A, b, method)
  if method == 1
    # QR = A
    # Q' = Q^-1
    # Ax=b
    # QRx = b
    # Rx = Q'b
    [Q, R] = qr(A);
    x = backsubstitution(R, Q' * b);

  elseif method == 2
    # R' * R = A
    # R' * R * x = b
    if(issymmetric(A))
      R = chol(A)
      x = backsubstitution(R, forwardsubstitution(R', b));
    else
      printf("The matrix is not symmetrical, Cholesky cannot be used.\n")
      x = 1;
    endif

  elseif method == 3
    [L, U, P] = lu(A);
    # P * A = LU
    # Ax = b
    # PAx = Pb
    # LUx = Pb
    #
    x = backsubstitution(U, forwardsubstitution(L, P * b));
  else
    disp("Invalid option")
    x = 1 ;
  endif
endfunction
