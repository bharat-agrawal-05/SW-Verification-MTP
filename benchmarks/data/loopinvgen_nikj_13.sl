;; Benchmark: loopinvgen_nikj_13
(set-logic LIA)

(synth-inv InvF ((n Int) (i Int) (k Int) (j Int)))

(define-fun PreF ((n Int) (i Int) (k Int) (j Int)) Bool
  (and (= i 0) (= k 0) (= j 0) (= n 28))
)

(define-fun TransF ((n Int) (i Int) (k Int) (j Int) (n! Int) (i! Int) (k! Int) (j! Int)) Bool
  (and (< i n) (= i! (+ i 1)) (= k! (+ k 1)) (= j! (+ j 1)) (= n! n))
)

(define-fun PostF ((n Int) (i Int) (k Int) (j Int)) Bool
  (or (< i n) (and (= k i) (= j i)))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((n Int) (i Int) (k Int) (j Int)) Bool
  (and (>= i 0) (<= i n) (= k i) (= j i) (= n 28))
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
