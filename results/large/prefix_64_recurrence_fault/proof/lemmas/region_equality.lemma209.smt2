; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x68774 (bvmul (_ bv4294967277 32) arg0_0)))
(and (distinct ?x68774 (_ bv0 32)) true)))
(check-sat)
