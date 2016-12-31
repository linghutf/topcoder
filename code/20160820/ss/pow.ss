(define (pow x y n)
  (if (< n 1)
    y
    (pow x (* x y) (- n 1))))

(define x (string->number (list-ref (command-line) 1)))
(define n (string->number (list-ref (command-line) 2)))

(printf "~d^(~d)=~d\n" x n (pow x 1 n))
