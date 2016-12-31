(define lat?
  (lambda (l)
    (cond
      ((null? l) #t)
      ((atom? (car l)) (lat? (cdr l)))
      (else #f))))

(define atom?
  (lambda (x)
    (and (not (pair? x)) (not (null? x)))))

(define x (string->number (list-ref (command-line) 1)))
(printf "~d\n" (lat? x))
