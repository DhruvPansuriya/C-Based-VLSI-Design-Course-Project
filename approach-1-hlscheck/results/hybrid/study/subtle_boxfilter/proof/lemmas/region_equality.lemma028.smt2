; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x352993 (bvmul (_ bv4294967295 32) arg0_12)))
(and (distinct ?x352993 (_ bv0 32)) true)))
(check-sat)
