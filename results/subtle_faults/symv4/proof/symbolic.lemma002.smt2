; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x414701 (bvmul arg0_4 arg1_1)))
(and (distinct ?x414701 (_ bv0 32)) true)))
(check-sat)
