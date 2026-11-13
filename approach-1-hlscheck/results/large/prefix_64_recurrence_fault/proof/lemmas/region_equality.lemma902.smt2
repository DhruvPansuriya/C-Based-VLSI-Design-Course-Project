; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x13838 (bvmul (_ bv4294967255 32) arg0_0)))
(and (distinct ?x13838 (_ bv0 32)) true)))
(check-sat)
