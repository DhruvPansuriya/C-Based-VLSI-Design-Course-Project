; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x369305 (bvmul (_ bv4294967294 32) arg0_1)))
(and (distinct ?x369305 (_ bv0 32)) true)))
(check-sat)
