(set-logic LIA)

(synth-inv inv_fun ((i Int) (j Int) (n Int) (k Int)))

(define-fun pre_fun ((i Int) (j Int) (n Int) (k Int)) Bool
    (and (or (= n 1) (= n 2)) (= i 0) (= j 0)))
(define-fun trans_fun ((i Int) (j Int) (n Int) (k Int) (i! Int) (j! Int) (n! Int) (k! Int)) Bool
    (or (and (> i k) (= i! i) (= j! j) (= n! n) (= k! k)) (and (<= i k) (= i! (+ i 1)) (= j! (+ j n)) (= n! n) (= k! k))))
(define-fun post_fun ((i Int) (j Int) (n Int) (k Int)) Bool
    (=> (> i k) (or (not (= n 1)) (= i j))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((i Int) (j Int) (n Int) (k Int)) Bool (or (and (<= i k) (= j (* n i)) (= k (- n 1))) (= j (* n i))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

