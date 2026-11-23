; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x20673 (bvmul arg0_15 arg0_7)))
(and (distinct ?x20673 (_ bv0 32)) true)))
(check-sat)
