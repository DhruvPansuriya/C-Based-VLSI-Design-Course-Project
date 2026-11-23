; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x418225 (bvmul arg0_3 arg0_7)))
(and (distinct ?x418225 (_ bv0 32)) true)))
(check-sat)
