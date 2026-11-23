; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x349499 (bvmul (_ bv4294967295 32) arg0_7)))
(and (distinct ?x349499 (_ bv0 32)) true)))
(check-sat)
