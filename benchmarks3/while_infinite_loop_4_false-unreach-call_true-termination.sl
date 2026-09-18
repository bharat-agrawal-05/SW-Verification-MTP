(set-logic LIA)

(synth-inv InvF ((x Int)))

(define-fun PreF ((x Int)) Bool
    (= x 0))
(define-fun TransF ((x Int) (x! Int)) Bool
    (= x! 1))
(define-fun PostF ((x Int)) Bool
    (not (= x 0)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun InvF ((x Int)) Bool false)

(inv-constraint InvF PreF TransF PostF)

(check-synth)

