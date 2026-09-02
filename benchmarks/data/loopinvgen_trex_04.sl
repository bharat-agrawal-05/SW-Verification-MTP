;; Benchmark: loopinvgen_trex_04
(set-logic LIA)

(synth-inv InvF ((x Int) (y Int) (k Int)))

(define-fun PreF ((x Int) (y Int) (k Int)) Bool
  (and (= x 1) (= y 1) (= k 20))
)

(define-fun TransF ((x Int) (y Int) (k Int) (x! Int) (y! Int) (k! Int)) Bool
  (and (< x k) (= x! (+ x y)) (= y! y) (= k! k))
)

(define-fun PostF ((x Int) (y Int) (k Int)) Bool
  (or (< x k) (>= x 1))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((x Int) (y Int) (k Int)) Bool
  (and (>= x 1) (= y 1) (= k 20))
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
