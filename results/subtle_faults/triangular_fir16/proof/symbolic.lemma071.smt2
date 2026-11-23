; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x369562 (bvmul (_ bv4294967294 32) arg0_5)))
(and (distinct ?x369562 (_ bv0 32)) true)))
(check-sat)
