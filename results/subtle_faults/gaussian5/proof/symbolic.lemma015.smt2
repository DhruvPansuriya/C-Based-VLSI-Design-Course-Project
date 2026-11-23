; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x370398 (bvmul (_ bv2 32) arg0_12)))
(and (distinct ?x370398 (_ bv0 32)) true)))
(check-sat)
