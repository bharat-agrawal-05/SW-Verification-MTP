(set-logic LIA)

(synth-inv inv_fun ((x Int) (i Int) (j Int)))

(define-fun pre_fun ((x Int) (i Int) (j Int)) Bool
    (and (= j 0) (> x 0) (= i 0)))
(define-fun trans_fun ((x Int) (i Int) (j Int) (x! Int) (i! Int) (j! Int)) Bool
    (or (and (< i x) (= j! (+ j 2)) (= i! (+ i 1)) (= x! x)) (and (>= i x) (= j! j) (= i! i) (= x! x))))
(define-fun post_fun ((x Int) (i Int) (j Int)) Bool
    (=> (not (< i x)) (= j (* 2 x))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (i Int) (j Int)) Bool (and (>= i 0) (>= j 0) (<= i x) (= j (* 2 i))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

