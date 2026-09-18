(set-logic LIA)

(synth-inv inv_fun ((i Int) (b Int) (n Int)))

(define-fun pre_fun ((i Int) (b Int) (n Int)) Bool
    (and (= i 0) (< i n)))
(define-fun trans_fun ((i Int) (b Int) (n Int) (i! Int) (b! Int) (n! Int)) Bool
    (and (< i n) (= n! n) (or (and (= b! 0) (= i! i)) (and (not (= b! 0)) (= i! (+ i 1))))))
(define-fun post_fun ((i Int) (b Int) (n Int)) Bool
    (or (< i n) (and (= i n) (not (= b 0)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((i Int) (b Int) (n Int)) Bool (and (<= 0 i n) (=> (= b 0) (< i n))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

