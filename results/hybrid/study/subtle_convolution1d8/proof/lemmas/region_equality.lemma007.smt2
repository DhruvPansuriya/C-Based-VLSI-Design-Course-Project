; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x440671 (bvmul (_ bv3 32) arg0_5)))
(and (distinct ?x440671 (_ bv0 32)) true)))
(check-sat)
