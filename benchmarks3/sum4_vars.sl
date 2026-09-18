(set-logic LIA)

(synth-inv inv_fun ((i Int) (sn Int) (size Int) (v1 Int) (v2 Int) (v3 Int)))

(define-fun pre_fun ((i Int) (sn Int) (size Int) (v1 Int) (v2 Int) (v3 Int)) Bool
    (and (= sn 0) (= i 1)))
(define-fun trans_fun ((i Int) (sn Int) (size Int) (v1 Int) (v2 Int) (v3 Int) (i! Int) (sn! Int) (size! Int) (v1! Int) (v2! Int) (v3! Int)) Bool
    (and (= size! size) (and (= i! (+ i 1)) (and (<= i size) (= sn! (+ sn 1))))))
(define-fun post_fun ((i Int) (sn Int) (size Int) (v1 Int) (v2 Int) (v3 Int)) Bool
    (or (<= i size) (or (= sn size) (= sn 0))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((i Int) (sn Int) (size Int) (v1 Int) (v2 Int) (v3 Int)) Bool (and (or (<= i size) (= sn 0) (= sn size)) (= sn (+ -1 i))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

