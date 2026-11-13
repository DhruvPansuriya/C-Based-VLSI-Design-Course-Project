; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x338310 (bvmul (_ bv3 32) arg0_4)))
(and (distinct ?x338310 (_ bv0 32)) true)))
(check-sat)
