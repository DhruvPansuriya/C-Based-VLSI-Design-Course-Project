; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x512213 (bvmul (_ bv4294967295 32) arg0_9)))
(and (distinct ?x512213 (_ bv0 32)) true)))
(check-sat)
