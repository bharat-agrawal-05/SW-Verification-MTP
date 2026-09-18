(set-logic NIA)

(synth-inv inv-f ((n Int) (s Int) (i Int) (j Int)))

(define-fun pre-f ((n Int) (s Int) (i Int) (j Int)) Bool
    (and (<= 1 n) (<= n 1000) (= s 0) (= j 0) (= i 1)))
(define-fun trans-f ((n Int) (s Int) (i Int) (j Int) (n! Int) (s! Int) (i! Int) (j! Int)) Bool
    (and (<= i n) (= s! (+ s i)) (= j! i) (= i! (+ i 1)) (= n! n)))
(define-fun post-f ((n Int) (s Int) (i Int) (j Int)) Bool
    (or (<= i n) (= (* 2 s) (* n (+ n 1)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv-f ((n Int) (s Int) (i Int) (j Int)) Bool (and (<= 1 n) (<= n 1000) (<= 1 i) (<= i (+ n 1)) (<= 0 j) (= (* 2 s) (* i (+ i -1)))))

(inv-constraint inv-f pre-f trans-f post-f)

(check-synth)

