; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x365263 (bvmul arg0_13 arg1_3)))
(and (distinct ?x365263 (_ bv0 32)) true)))
(check-sat)
