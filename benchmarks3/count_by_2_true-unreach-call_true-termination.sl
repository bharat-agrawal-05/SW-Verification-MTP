(set-logic LIA)

(synth-inv InvF ((i Int)))

(define-fun PreF ((i Int)) Bool
    (= i 0))
(define-fun TransF ((i Int) (i! Int)) Bool
    (and (< i 1000000) (= i! (+ i 2))))
(define-fun PostF ((i Int)) Bool
    (or (< i 1000000) (= i 1000000)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun InvF ((i Int)) Bool (and (>= i 0) (<= i 1000001) (= (mod i 2) 0)))

(inv-constraint InvF PreF TransF PostF)

(check-synth)

