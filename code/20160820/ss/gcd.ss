#! /usr/bin/scheme --script

; 定义函数
(define (mygcd x y)
  (cond [(zero? y) x]
    [else (mygcd y (modulo x y))]))

(define ogcd
  (lambda (a b)
    (if (zero? b)
      a
      (ogcd b (modulo a b)))))

; 解析命令行参数
;(for-each
;  (lambda (x) (printf "~r" (ogcd x))))
(define filename (list-ref (command-line) 0))
(define x (string->number (list-ref (command-line) 1)))
(define y (string->number (list-ref (command-line) 2)))
(printf "~d and ~d = ~d\n" x y (ogcd x y))
