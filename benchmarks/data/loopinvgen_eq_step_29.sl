;; Benchmark: loopinvgen_eq_step_29
(set-logic LIA)

(synth-inv InvF ((x Int) (y Int)))

(define-fun PreF ((x Int) (y Int)) Bool
  (= y x)
)

(define-fun TransF ((x Int) (y Int) (x! Int) (y! Int)) Bool
  (and (< x 1450) (= x! (+ x 3)) (= y! (+ y 3)))
)

(define-fun PostF ((x Int) (y Int)) Bool
  (or (< x 1450) (= x y))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((x Int) (y Int)) Bool
  (= x y)
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
