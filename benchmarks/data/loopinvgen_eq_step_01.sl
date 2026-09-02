;; Benchmark: loopinvgen_eq_step_01
(set-logic LIA)

(synth-inv InvF ((x Int) (y Int)))

(define-fun PreF ((x Int) (y Int)) Bool
  (= y x)
)

(define-fun TransF ((x Int) (y Int) (x! Int) (y! Int)) Bool
  (and (< x 50) (= x! (+ x 2)) (= y! (+ y 2)))
)

(define-fun PostF ((x Int) (y Int)) Bool
  (or (< x 50) (= x y))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((x Int) (y Int)) Bool
  (= x y)
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
