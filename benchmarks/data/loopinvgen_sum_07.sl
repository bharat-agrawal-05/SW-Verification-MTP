;; Benchmark: loopinvgen_sum_07
(set-logic LIA)

(synth-inv InvF ((i Int) (s Int) (n Int)))

(define-fun PreF ((i Int) (s Int) (n Int)) Bool
  (and (= i 0) (= s 0) (= n 17))
)

(define-fun TransF ((i Int) (s Int) (n Int) (i! Int) (s! Int) (n! Int)) Bool
  (and (< i n) (= s! (+ s 1)) (= i! (+ i 1)) (= n! n))
)

(define-fun PostF ((i Int) (s Int) (n Int)) Bool
  (or (< i n) (= s i))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((i Int) (s Int) (n Int)) Bool
  (and (>= i 0) (<= i n) (= s i) (= n 17))
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
