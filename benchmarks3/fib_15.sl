(set-logic LIA)

(synth-inv inv_fun ((n Int) (j Int) (k Int)))

(define-fun pre_fun ((n Int) (j Int) (k Int)) Bool
    (and (= j 0) (> n 0) (> k n)))
(define-fun trans_fun ((n Int) (j Int) (k Int) (n! Int) (j! Int) (k! Int)) Bool
    (or (and (< j n) (= j! (+ j 1)) (= k! (- k 1)) (= n! n)) (and (>= j n) (= j! j) (= k! k) (= n! n))))
(define-fun post_fun ((n Int) (j Int) (k Int)) Bool
    (=> (not (< j n)) (>= k 0)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((n Int) (j Int) (k Int)) Bool (and (>= j 0) (>= k 0) (<= j n) (>= k (- n)) (>= (+ j k) n)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

