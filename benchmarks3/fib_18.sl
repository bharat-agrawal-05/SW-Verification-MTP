(set-logic LIA)

(synth-inv inv_fun ((b Int) (j Int) (n Int) (flag Int)))

(define-fun pre_fun ((b Int) (j Int) (n Int) (flag Int)) Bool
    (and (= j 0) (> n 0) (= b 0)))
(define-fun trans_fun ((b Int) (j Int) (n Int) (flag Int) (b! Int) (j! Int) (n! Int) (flag! Int)) Bool
    (or (and (< b n) (= flag 1) (= j! (+ j 1)) (= b! (+ b 1)) (= n! n) (= flag! flag)) (and (< b n) (not (= flag 1)) (= j! j) (= b! (+ b 1)) (= n! n) (= flag! flag)) (and (>= b n) (= j! j) (= b! b) (= n! n) (= flag! flag))))
(define-fun post_fun ((b Int) (j Int) (n Int) (flag Int)) Bool
    (=> (not (< b n)) (or (not (= flag 1)) (= j n))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((b Int) (j Int) (n Int) (flag Int)) Bool (and (>= b 0) (<= b n) (or (and (= flag 1) (= j b)) (and (not (= flag 1)) (= j 0)))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

