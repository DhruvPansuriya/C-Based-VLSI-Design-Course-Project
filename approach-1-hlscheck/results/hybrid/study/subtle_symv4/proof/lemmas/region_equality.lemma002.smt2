; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x20673 (bvmul arg0_4 arg1_1)))
(and (distinct ?x20673 (_ bv0 32)) true)))
(check-sat)
