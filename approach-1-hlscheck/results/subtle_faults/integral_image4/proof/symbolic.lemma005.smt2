; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x381839 (bvmul (_ bv4294967294 32) arg0_2)))
(and (distinct ?x381839 (_ bv0 32)) true)))
(check-sat)
