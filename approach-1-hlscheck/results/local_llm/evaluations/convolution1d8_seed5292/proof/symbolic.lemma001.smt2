; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x241759 (bvmul (_ bv3 32) arg0_1)))
(and (distinct ?x241759 (_ bv0 32)) true)))
(check-sat)
