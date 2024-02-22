; Remove all numerical atoms that are multiples of three, at any given level.
(defun rm (l)
    (cond
        ((and (numberp l) (equal (mod l 3) 0)) NIL)
        ((atom l) (list l))
        (t (list (mapcan #'(lambda (x) (rm x)) l)))
    )
)

; -------------------------------------------------------

; Replace each element e with e1
; (defun repl(l e e1)
;     (cond
;         ((equal l e) e1)
;         ((atom l) l)
;         (t (mapcar #'(lambda(x)(repl x e e1)) l))
;     )
; )

; -------------------------------------------------------

; Remove all non-numerical atoms that are vowels
(defun check-vowel(element l)
    (cond
        ((equal element (car l)) 0)
        ((not(equal element (car l))) 1)
        (t (check-vowel element (cdr l)))
    )
)

(defun repl(l)
    (cond
        ((and (atom l) (equal (check-vowel l '(a e i o u)) 0)) nil)
        ((atom l) (list l))
        (t (list(mapcan #'(lambda(x)(repl x)) l)))
    )
)

; -------------------------------------------------------

; Remove all duplicates at even levels

(defun removeDuplicates(l el)
    (cond
        ((null l) nil)
        ((equal (car l) el) (removeDuplicates (cdr l) el))
        (t (cons (car l) (removeDuplicates (cdr l) el)))

    )

)

(defun removeAllDuplicates(l)
    (cond
        ((null l) nil)
        ((member (car l) (cdr l)) (removeAllDuplicates (removeDuplicates (cdr l) (car l))))
        (t (cons (car l) (removeAllDuplicates (cdr l) ))))

)

(defun rmvEvenLvl(l lvl)
    (cond
        ((and (listp l) (equal (mod lvl 2) 0)) (list (removeAllDuplicates l)))
        ((atom l) (list l))
        (t (list (mapcan #'(lambda(x)(rmvEvenLvl x (+ lvl 1))) l)))
    )
)

; -------------------------------------------------------

; The maximum atom on odd levels should be even

(defun maximum-atom(l crtmax)
    (cond
        ((and (numberp (car l)) (< crtmax (car l))) (maximum-atom (cdr l) (car l)))
        ((null l) crtmax)
        (t (maximum-atom (cdr l) crtmax))
    )
)

(defun cnt(l lvl)
    (cond
        ((atom l) 0)
        ((and (listp l) (equal (mod (maximum-atom l -1) 2) 0) (equal (mod lvl 2) 1))
            (+ 1 (apply #'+ (mapcar #'(lambda (x) (cnt x (+ 1 lvl))) l))))
        (t (apply #'+(mapcar #'(lambda (x) (cnt x (+ 1 lvl))) l)))
    )
)

; -------------------------------------------------------

; Compute the number of sublists where the first numerical atom is 5

(defun reverseList(l)
    (cond
        ((null l) nil)
        (t (append (reverseList (cdr l)) (list (car l))))
    )
)

(defun checkFive(l)
    (cond
        ((null l) 0)
        ((and (listp l) (numberp (car (reverseList l))) (equal (car (reverseList l)) 5)) 1)
        (t 0)
    )
)

(defun cnt-sub(l)
    (cond
        ((atom l) 0)
        ((and (listp l) (equal (checkFive l) 1))
            (+ 1 (apply #'+ (mapcar #'(lambda(x)(cnt-sub x)) l))))
        (t (apply #'+ (mapcar #'(lambda(x)(cnt-sub x)) l)))
    )
)

; -------------------------------------------------------

; Compute the number of sublists where the number of non-numerical atoms
; on even levels is odd

(defun nr-of-non(l)
    (cond
        ((null l) 0)
        ((and (atom (car l)) (not (numberp (car l))))
            (+ 1 (nr-of-non (cdr l))))
        (t (nr-of-non (cdr l)))
    )
)

(defun count-atoms(l lvl)
    (cond
        ((null l) 0)
        ((atom l) 0)
        ((and
            (listp l)
            (= (mod (nr-of-non l) 2) 1)
            (= (mod lvl 2) 0))
                (+ 1 (apply #'+ (mapcar #'(lambda(x)(count-atoms x (+ lvl 1))) l))))
        (t (apply #'+ (mapcar #'(lambda(x)(count-atoms x (+ lvl 1))) l)))
    )
)

