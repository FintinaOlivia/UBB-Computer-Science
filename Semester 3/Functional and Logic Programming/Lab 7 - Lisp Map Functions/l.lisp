; 5. Write a function that computes the sum of even numbers
; and then decrease the sum of odd numbers from that sum, at any level of a list.

; Mathematical model
; add-even-sub-odd(number) =
;  = number, if number % 2 == 0
;  = -number, otherwise

; Signature: add-even-sub-odd(integer) 
; Flow model: (i o)

(defun add-even-sub-odd(n)
     (cond
         ((equal 0 (mod n 2)) n)
         (t (- n))
     )
)

; Signature: sum-total(list)
; Flow model: (i o)

(defun sum-total(lst)
     (cond
         ((numberp lst) (add-even-sub-odd lst))
         ((atom lst) 0)
         (t (apply '+ (mapcar #'sum-total lst)))
     )
)

; (print "Sum of even numbers and then decrease the sum of odd numbers from that sum: ")
; (print (sum-total '(1 2 3 b 4 (5 6) a 7 8 9 10)))
; (print "-----------------------------------------------")

