; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x366291 (bvmul (_ bv2 32) arg0_8)))
(and (distinct ?x366291 (_ bv0 32)) true)))
(check-sat)
