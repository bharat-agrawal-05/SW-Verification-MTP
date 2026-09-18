(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (xa Int) (ya Int)))

(define-fun pre_fun ((x Int) (y Int) (xa Int) (ya Int)) Bool
    (and (= xa 0) (= ya 0)))
(define-fun trans_fun ((x Int) (y Int) (xa Int) (ya Int) (x! Int) (y! Int) (xa! Int) (ya! Int)) Bool
    (and (= x! (+ 1 (+ xa (* 2 ya)))) (or (= y! (+ (- ya (* 2 xa)) x!)) (= y! (- (- ya (* 2 xa)) x!))) (= xa! (- x! (* 2 y!))) (= ya! (+ (* 2 x!) y!))))
(define-fun post_fun ((x Int) (y Int) (xa Int) (ya Int)) Bool
    (>= (+ xa (* 2 ya)) 0))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (xa Int) (ya Int)) Bool (and (>= (+ xa (* 2 ya)) 0) (or (= xa 0) (not (and (= xa (mod (- ya xa) 3)) (= ya (mod (- xa ya) 3)))))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

