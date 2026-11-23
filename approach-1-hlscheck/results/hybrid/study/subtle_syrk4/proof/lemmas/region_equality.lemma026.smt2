; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x21399 (bvmul arg0_10 arg0_14)))
(and (distinct ?x21399 (_ bv0 32)) true)))
(check-sat)
