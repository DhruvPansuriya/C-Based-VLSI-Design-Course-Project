; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x454333 (bvmul (_ bv2 32) arg0_0)))
(and (distinct ?x454333 (_ bv0 32)) true)))
(check-sat)
