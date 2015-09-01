(defun list_reverse (L)
 (cond
  ((null L) nil)
  ((null (cdr L)) L)
  (T (append (list_reverse (cdr L)) (list (car L))))
 )
) 