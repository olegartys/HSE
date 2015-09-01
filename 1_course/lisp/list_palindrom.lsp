(defun list_palindrom (L)
 (cond
  ((null L) nil)
  (T (equal L (list_reverse L)))
 )
)