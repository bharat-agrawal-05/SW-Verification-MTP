(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (i Int) (j Int)))

(define-fun pre_fun ((x Int) (y Int) (i Int) (j Int)) Bool
    (and (= j 0) (and (= i 0) (or (= y 1) (= y 2)))))
(define-fun trans_fun ((x Int) (y Int) (i Int) (j Int) (x! Int) (y! Int) (i! Int) (j! Int)) Bool
    (and (<= i x) (and (= x! x) (and (= y! y) (and (= i! (+ i 1)) (= j! (+ j y)))))))
(define-fun post_fun ((x Int) (y Int) (i Int) (j Int)) Bool
    (or (<= i x) (or (not (= y 1)) (= i j))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (i Int) (j Int)) Bool (or (and (<= 0 i) (<= i x) (= j (* y i))) (and (<= 0 i) (< x i) (or (= i j) (not (= y 1))))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

