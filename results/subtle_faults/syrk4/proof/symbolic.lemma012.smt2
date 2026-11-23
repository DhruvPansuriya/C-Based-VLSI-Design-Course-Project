; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x352616 (bvmul arg0_11 arg0_7)))
(and (distinct ?x352616 (_ bv0 32)) true)))
(check-sat)
