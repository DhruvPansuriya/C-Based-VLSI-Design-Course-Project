; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x432879 (bvmul arg0_11 arg0_15)))
(and (distinct ?x432879 (_ bv0 32)) true)))
(check-sat)
