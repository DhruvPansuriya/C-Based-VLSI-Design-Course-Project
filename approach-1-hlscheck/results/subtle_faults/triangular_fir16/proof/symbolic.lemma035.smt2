; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x3034 (bvmul (_ bv4294967295 32) arg0_7)))
(and (distinct ?x3034 (_ bv0 32)) true)))
(check-sat)
