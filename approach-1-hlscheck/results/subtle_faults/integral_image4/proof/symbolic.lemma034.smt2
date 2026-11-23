; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x19826 (bvmul (_ bv4294967292 32) arg0_9)))
(and (distinct ?x19826 (_ bv0 32)) true)))
(check-sat)
