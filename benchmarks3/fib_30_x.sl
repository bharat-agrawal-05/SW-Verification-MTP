(set-logic LIA)

(synth-inv inv_fun ((i Int) (c Int) (n Int)))

(define-fun pre_fun ((i Int) (c Int) (n Int)) Bool
    (and (= i 0) (= c 0) (> n 0)))
(define-fun trans_fun ((i Int) (c Int) (n Int) (i! Int) (c! Int) (n! Int)) Bool
    (or (and (>= i n) (= i! i) (= c! c) (= n! n)) (and (< i n) (= i! (+ i 1)) (= c! (+ c i)) (= n! n))))
(define-fun post_fun ((i Int) (c Int) (n Int)) Bool
    (=> (>= i n) (>= c 0)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((i Int) (c Int) (n Int)) Bool (and (>= i 0) (>= c 0) (<= i n) (<= c (+ (* i n) (* (- i 1) i 2)))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

