(set-logic LIA)

(synth-inv inv_fun ((y Int) (z Int) (c Int)))

(define-fun pre_fun ((y Int) (z Int) (c Int)) Bool
    (and (and (= c 0) (>= y 0)) (and (>= 127 y) (= z (* 36 y)))))
(define-fun trans_fun ((y Int) (z Int) (c Int) (y! Int) (z! Int) (c! Int)) Bool
    (and (and (and (< c 36) (= z! (+ z 1))) (= c! (+ c 1))) (= y! y)))
(define-fun post_fun ((y Int) (z Int) (c Int)) Bool
    (not (and (< c 36) (or (< z 0) (>= z 4608)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((y Int) (z Int) (c Int)) Bool (and (and (>= y 0) (<= y 127)) (and (>= z 0) (<= z 4608)) (>= (+ (* 36 y) c) z)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

