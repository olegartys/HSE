(defun list_deep (L)
 (cond
  ((null L) 0)
  ((atom L) 0)
  (T (max (+ 1 (list_deep (car L))) (list_deep (cdr L))))
 )
)