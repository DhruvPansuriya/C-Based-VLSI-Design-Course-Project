; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x469857 (bvmul (_ bv2 32) arg0_4)))
(and (distinct ?x469857 (_ bv0 32)) true)))
(check-sat)
