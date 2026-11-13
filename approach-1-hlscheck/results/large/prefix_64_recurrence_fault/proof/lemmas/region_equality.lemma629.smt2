; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x54390 (bvmul (_ bv4294967262 32) arg0_0)))
(and (distinct ?x54390 (_ bv0 32)) true)))
(check-sat)
