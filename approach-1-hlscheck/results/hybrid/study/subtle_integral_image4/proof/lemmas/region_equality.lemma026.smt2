; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x400121 (bvmul (_ bv4294967294 32) arg0_9)))
(and (distinct ?x400121 (_ bv0 32)) true)))
(check-sat)
