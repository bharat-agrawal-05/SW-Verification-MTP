(set-logic LIA)

(synth-inv inv_fun ((c Int) (n Int)))

(define-fun pre_fun ((c Int) (n Int)) Bool
    (and (= c 0) (> n 0)))
(define-fun trans_fun ((c Int) (n Int) (c! Int) (n! Int)) Bool
    (or (and (and (> c n) (= c! (+ c 1))) (= n! n)) (and (and (= c n) (= c! 1)) (= n! n))))
(define-fun post_fun ((c Int) (n Int)) Bool
    (and (or (= c n) (and (>= c 0) (<= c n))) (or (not (= c n)) (> n (- 1)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((c Int) (n Int)) Bool (and (<= 0 c n) (<= (+ c 1) n)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

