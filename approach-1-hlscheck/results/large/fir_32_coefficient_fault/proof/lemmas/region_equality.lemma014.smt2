; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_20 () (_ BitVec 32))
(assert
 (let ((?x19949 (bvmul (_ bv4294967294 32) arg0_20)))
(and (distinct ?x19949 (_ bv0 32)) true)))
(check-sat)
