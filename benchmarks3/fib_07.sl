(set-logic LIA)

(synth-inv inv_fun ((i Int) (n Int) (a Int) (b Int)))

(define-fun pre_fun ((i Int) (n Int) (a Int) (b Int)) Bool
    (and (= i 0) (= a 0) (= b 0) (>= n 0)))
(define-fun trans_fun ((i Int) (n Int) (a Int) (b Int) (i! Int) (n! Int) (a! Int) (b! Int)) Bool
    (or (and (< i n) (= i! (+ i 1)) (= a! (+ a 1)) (= b! (+ b 2)) (= n! n)) (and (< i n) (= i! (+ i 1)) (= a! (+ a 2)) (= b! (+ b 1)) (= n! n)) (and (>= i n) (= i! i) (= a! a) (= b! b) (= n! n))))
(define-fun post_fun ((i Int) (n Int) (a Int) (b Int)) Bool
    (=> (not (< i n)) (= (+ a b) (+ (+ n n) n))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((i Int) (n Int) (a Int) (b Int)) Bool (and (<= i n) (= (+ a b) (+ i (+ i i)))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

