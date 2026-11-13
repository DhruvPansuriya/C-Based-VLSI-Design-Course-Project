; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x1550 (bvmul arg0_11 arg0_3)))
(and (distinct ?x1550 (_ bv0 32)) true)))
(check-sat)
