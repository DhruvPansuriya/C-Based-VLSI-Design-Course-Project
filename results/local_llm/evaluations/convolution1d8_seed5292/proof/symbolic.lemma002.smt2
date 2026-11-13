; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x26434 (bvmul (_ bv5 32) arg0_2)))
(and (distinct ?x26434 (_ bv0 32)) true)))
(check-sat)
