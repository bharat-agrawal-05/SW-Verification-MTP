;; Benchmark: loopinvgen_bound_07
(set-logic LIA)

(synth-inv InvF ((x Int) (y Int)))

(define-fun PreF ((x Int) (y Int)) Bool
  (and (= x 1) (= y 0))
)

(define-fun TransF ((x Int) (y Int) (x! Int) (y! Int)) Bool
  (and (< y 700) (= x! 0) (= y! (+ y 1)))
)

(define-fun PostF ((x Int) (y Int)) Bool
  (or (< y 700) (not (= x 1)))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((x Int) (y Int)) Bool
  (or (and (= x 1) (< y 700)) (and (= x 0) (<= y 700)))
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
