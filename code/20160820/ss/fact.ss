; 使用命令行参数计算乘方

(define fact
  (lambda (n)
  (define (fact-iter n result)
    (if (zero? n)
      result
      (fact-iter (- n 1) (* result n))))

    (fact-iter n 1)))

; command line args

(define num (string->number (list-ref (command-line) 1)))
(printf "~d\n" (fact num))
