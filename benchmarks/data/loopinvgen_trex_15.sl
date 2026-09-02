;; Benchmark: loopinvgen_trex_15
(set-logic LIA)

(synth-inv InvF ((x Int) (y Int) (k Int)))

(define-fun PreF ((x Int) (y Int) (k Int)) Bool
  (and (= x 1) (= y 1) (= k 75))
)

(define-fun TransF ((x Int) (y Int) (k Int) (x! Int) (y! Int) (k! Int)) Bool
  (and (< x k) (= x! (+ x y)) (= y! y) (= k! k))
)

(define-fun PostF ((x Int) (y Int) (k Int)) Bool
  (or (< x k) (>= x 1))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((x Int) (y Int) (k Int)) Bool
  (and (>= x 1) (= y 1) (= k 75))
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
