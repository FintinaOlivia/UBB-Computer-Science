combinations([], 1, []).
combinations([H|_], 1, [H]).
combinations([_|T], N, R) :-
    combinations(T, N, R).
combinations([H|T], N, [H|T1]) :-
    N > 1,
    N1 is N - 1,
    combinations(T, N1, T1).


permutations([], []).
permutations([H|T], R) :-
    permutations(T, RP),
    myAppend(H, RP, R).


arrangements(_, 0, []).
arrangements(L,K,RR):-
    combinations(L,K,R),
    permutations(R,RR).


subsets([],[]).
subsets([_|T], R) :-
    subsets(T,R).
subsets([H|T], [H,R]) :-
    subsets(T,R).

