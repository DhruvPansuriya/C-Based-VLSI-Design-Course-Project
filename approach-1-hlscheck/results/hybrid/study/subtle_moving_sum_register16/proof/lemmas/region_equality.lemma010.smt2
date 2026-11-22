; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x704580 (bvmul (_ bv4294967295 32) arg0_7)))
(and (distinct ?x704580 (_ bv0 32)) true)))
(check-sat)
