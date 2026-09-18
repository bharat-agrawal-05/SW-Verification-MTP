(set-logic LIA)

(synth-inv inv_fun ((i Int) (sn Int)))

(define-fun pre_fun ((i Int) (sn Int)) Bool
    (and (= sn 0) (= i 1)))
(define-fun trans_fun ((i Int) (sn Int) (i! Int) (sn! Int)) Bool
    (and (= i! (+ i 1)) (and (<= i 8) (= sn! (+ sn 1)))))
(define-fun post_fun ((i Int) (sn Int)) Bool
    (or (<= i 8) (or (= sn 8) (= sn 0))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((i Int) (sn Int)) Bool (and (<= 1 i) (<= i 9) (<= 0 sn) (<= sn 8) (= sn (- i 1))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

