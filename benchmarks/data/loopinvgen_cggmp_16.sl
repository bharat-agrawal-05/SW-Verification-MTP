;; Benchmark: loopinvgen_cggmp_16
(set-logic LIA)

(synth-inv InvF ((i Int) (j Int)))

(define-fun PreF ((i Int) (j Int)) Bool
  (and (= i 1) (= j 160))
)

(define-fun TransF ((i Int) (j Int) (i! Int) (j! Int)) Bool
  (and (>= j i) (= i! (+ i 2)) (= j! (- j 1)))
)

(define-fun PostF ((i Int) (j Int)) Bool
  (or (>= j i) (= (+ (* 2 j) i) 321))
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ((i Int) (j Int)) Bool
  (= (+ (* 2 j) i) 321)
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
