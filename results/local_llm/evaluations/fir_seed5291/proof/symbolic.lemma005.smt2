; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x115 (bvmul (_ bv4 32) arg0_3)))
(and (distinct ?x115 (_ bv0 32)) true)))
(check-sat)
