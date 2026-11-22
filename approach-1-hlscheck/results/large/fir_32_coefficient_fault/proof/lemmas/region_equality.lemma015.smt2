; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_21 () (_ BitVec 32))
(assert
 (let ((?x12664 (bvmul (_ bv4294967294 32) arg0_21)))
(and (distinct ?x12664 (_ bv0 32)) true)))
(check-sat)
