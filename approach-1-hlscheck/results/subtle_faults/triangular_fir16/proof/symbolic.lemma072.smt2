; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x1809 (bvmul (_ bv4294967294 32) arg0_6)))
(and (distinct ?x1809 (_ bv0 32)) true)))
(check-sat)
