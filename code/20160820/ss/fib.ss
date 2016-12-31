;!# /usr/bin/scheme --script
;斐波那契数列

(define (fibnacci n)
  (define (fib fst sec n)
    (if (<= n 2)
      sec
      (fib sec (+ fst sec) (- n 1))))
  (fib 1 1 n))


(define n (string->number (list-ref (command-line) 1)))

(printf "fib(~d)=~10d\n" n (fibnacci n))
(printf "time:~f\n" (time (fibnacci n)))
