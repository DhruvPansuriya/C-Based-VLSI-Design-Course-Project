; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x510565 (bvmul arg0_8 arg1_2)))
(and (distinct ?x510565 (_ bv0 32)) true)))
(check-sat)
