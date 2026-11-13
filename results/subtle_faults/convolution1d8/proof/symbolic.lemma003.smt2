; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x372198 (bvmul (_ bv3 32) arg0_3)))
(and (distinct ?x372198 (_ bv0 32)) true)))
(check-sat)
