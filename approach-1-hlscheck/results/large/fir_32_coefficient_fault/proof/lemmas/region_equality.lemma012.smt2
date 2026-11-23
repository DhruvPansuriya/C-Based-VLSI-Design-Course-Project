; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_19 () (_ BitVec 32))
(assert
 (let ((?x106 (bvmul (_ bv4294967294 32) arg0_19)))
(and (distinct ?x106 (_ bv0 32)) true)))
(check-sat)
