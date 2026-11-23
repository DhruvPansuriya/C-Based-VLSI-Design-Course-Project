; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x741332 (bvmul (_ bv4294967295 32) arg0_15)))
(and (distinct ?x741332 (_ bv0 32)) true)))
(check-sat)
