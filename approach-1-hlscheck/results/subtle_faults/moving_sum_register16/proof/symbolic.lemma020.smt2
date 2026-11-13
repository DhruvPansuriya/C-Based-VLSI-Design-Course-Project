; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x22350 (bvmul (_ bv4294967295 32) arg0_12)))
(and (distinct ?x22350 (_ bv0 32)) true)))
(check-sat)
