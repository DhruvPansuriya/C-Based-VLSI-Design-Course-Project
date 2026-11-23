; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x358910 (bvmul (_ bv3 32) arg0_3)))
(and (distinct ?x358910 (_ bv0 32)) true)))
(check-sat)
