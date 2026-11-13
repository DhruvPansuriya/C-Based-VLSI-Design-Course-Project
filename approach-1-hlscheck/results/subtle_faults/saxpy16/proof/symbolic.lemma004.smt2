; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x369332 (bvmul (_ bv4294967295 32) arg1_2)))
(and (distinct ?x369332 (_ bv0 32)) true)))
(check-sat)
