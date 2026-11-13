; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x741529 (bvmul arg0_15 arg0_3)))
(and (distinct ?x741529 (_ bv0 32)) true)))
(check-sat)
