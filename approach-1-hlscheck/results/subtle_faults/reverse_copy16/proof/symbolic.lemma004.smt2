; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x538737 (bvmul (_ bv4294967295 32) arg0_9)))
(and (distinct ?x538737 (_ bv0 32)) true)))
(check-sat)
