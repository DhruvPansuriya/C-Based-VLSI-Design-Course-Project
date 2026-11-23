; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x379531 (bvmul (_ bv4294967295 32) arg1_9)))
(and (distinct ?x379531 (_ bv0 32)) true)))
(check-sat)
