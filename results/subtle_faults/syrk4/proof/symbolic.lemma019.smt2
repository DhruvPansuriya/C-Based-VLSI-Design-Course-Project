; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x61950 (bvmul arg0_15 arg0_3)))
(and (distinct ?x61950 (_ bv0 32)) true)))
(check-sat)
