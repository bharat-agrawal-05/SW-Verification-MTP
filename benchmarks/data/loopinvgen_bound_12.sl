;; Benchmark: loopinvgen_bound_12
(set-logic LIA)

(synth-inv InvF ((x Int) (y Int)))

(define-fun PreF ((x Int) (y Int)) Bool
  (and (= x 1) (= y 0))
)

(define-fun TransF ((x Int) (y Int) (x! Int) (y! Int)) Bool
  (and (< y 1200) (= x! 0) (= y! (+ y 1)))
)

(define-fun PostF ((x Int) (y Int)) Bool
  (or (< y 1200) (not (= x 1)))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((x Int) (y Int)) Bool
  (or (and (= x 1) (< y 1200)) (and (= x 0) (<= y 1200)))
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
