; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x482387 (bvmul arg0_14 arg1_3)))
(and (distinct ?x482387 (_ bv0 32)) true)))
(check-sat)
