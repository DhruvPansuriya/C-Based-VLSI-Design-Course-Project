; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x380475 (bvmul (_ bv4294967295 32) arg0_2)))
(and (distinct ?x380475 (_ bv0 32)) true)))
(check-sat)
