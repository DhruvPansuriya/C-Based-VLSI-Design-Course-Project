; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x369171 (bvmul (_ bv3 32) arg0_7)))
(and (distinct ?x369171 (_ bv0 32)) true)))
(check-sat)
