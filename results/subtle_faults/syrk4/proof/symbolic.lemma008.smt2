; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x23484 (bvmul arg0_10 arg0_2)))
(and (distinct ?x23484 (_ bv0 32)) true)))
(check-sat)
