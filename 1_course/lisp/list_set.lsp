(defun list_set (L)
 (cond
  ((null L) nil)
  (T (not (equal (car L) (list_set (cdr L)))))
 )
) 
