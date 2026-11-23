; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(assert
 (let ((?x369823 (bvmul (_ bv4294967295 32) arg1_0)))
(and (distinct ?x369823 (_ bv0 32)) true)))
(check-sat)
