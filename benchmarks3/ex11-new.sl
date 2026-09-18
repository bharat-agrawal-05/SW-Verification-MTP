(set-logic LIA)

(synth-inv inv_fun ((c Int)))

(define-fun pre_fun ((c Int)) Bool
    (= c 0))
(define-fun trans_fun ((c Int) (c! Int)) Bool
    (or (and (not (= c 40)) (= c! (+ c 1))) (and (= c 40) (= c! 1))))
(define-fun post_fun ((c Int)) Bool
    (not (and (not (= c 40)) (or (< c 0) (> c 40)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((c Int)) Bool (or (= c 0) (= c 40) (and (<= 1 c) (<= c 39))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

