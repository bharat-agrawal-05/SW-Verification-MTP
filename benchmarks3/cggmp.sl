(set-logic LIA)

(synth-inv inv_fun ((i Int) (j Int)))

(define-fun pre_fun ((i Int) (j Int)) Bool
    (and (= i 1) (= j 10)))
(define-fun trans_fun ((i Int) (j Int) (i! Int) (j! Int)) Bool
    (and (and (>= j i) (= i! (+ i 2))) (= j! (- j 1))))
(define-fun post_fun ((i Int) (j Int)) Bool
    (not (and (< j i) (not (= j 6)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((i Int) (j Int)) Bool (and (not (and (not (<= i j)) (not (= j 6)))) (= (* -2 j) (+ -21 i))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

