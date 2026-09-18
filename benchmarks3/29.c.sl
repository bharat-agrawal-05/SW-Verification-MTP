(set-logic LIA)

(synth-inv inv-f ((n Int) (x Int) (n_0 Int) (x_0 Int) (x_1 Int) (x_2 Int) (x_3 Int)))

(define-fun pre-f ((n Int) (x Int) (n_0 Int) (x_0 Int) (x_1 Int) (x_2 Int) (x_3 Int)) Bool
    (and (= n n_0) (= x x_1) (= x_1 n_0)))
(define-fun trans-f ((n Int) (x Int) (n_0 Int) (x_0 Int) (x_1 Int) (x_2 Int) (x_3 Int) (n! Int) (x! Int) (n_0! Int) (x_0! Int) (x_1! Int) (x_2! Int) (x_3! Int)) Bool
    (or (and (= x_2 x) (= x_2 x!) (= n n!)) (and (= x_2 x) (> x_2 0) (= x_3 (- x_2 1)) (= x_3 x!) (= n n_0) (= n! n_0))))
(define-fun post-f ((n Int) (x Int) (n_0 Int) (x_0 Int) (x_1 Int) (x_2 Int) (x_3 Int)) Bool
    (or (not (and (= n n_0) (= x x_2))) (not (and (not (> x_2 0)) (>= n_0 0) (not (= x_2 0))))))

;; Verified Ground Truth Inductive Invariant
;; Source: SaswatPadhi/LoopInvGen (benchmarks/LIA/2018.NeurIPS_Code2Inv)
(define-fun inv-f ((n Int) (x Int) (n_0 Int) (x_0 Int) (x_1 Int) (x_2 Int) (x_3 Int)) Bool (or (>= x 0) (and (> x (- n 1)) (or (= x (- n 1)) (<= (* (- n x) 2) (* n (- n x)))))))

(inv-constraint inv-f pre-f trans-f post-f)

(check-synth)

