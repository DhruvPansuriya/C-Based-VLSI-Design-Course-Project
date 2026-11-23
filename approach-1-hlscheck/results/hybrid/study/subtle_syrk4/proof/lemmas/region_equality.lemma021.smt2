; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x728472 (bvmul arg0_12 arg0_4)))
(and (distinct ?x728472 (_ bv0 32)) true)))
(check-sat)
