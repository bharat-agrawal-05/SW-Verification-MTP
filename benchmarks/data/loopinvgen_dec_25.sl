;; Benchmark: loopinvgen_dec_25
(set-logic LIA)

(synth-inv InvF ((x Int) (y Int)))

(define-fun PreF ((x Int) (y Int)) Bool
  (and (= x 500) (= y 0))
)

(define-fun TransF ((x Int) (y Int) (x! Int) (y! Int)) Bool
  (and (> x 0) (= x! (- x 1)) (= y! (+ y 1)))
)

(define-fun PostF ((x Int) (y Int)) Bool
  (or (> x 0) (= (+ x y) 500))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((x Int) (y Int)) Bool
  (and (>= x 0) (>= y 0) (= (+ x y) 500))
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
