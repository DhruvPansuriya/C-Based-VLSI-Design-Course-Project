; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x22800 (bvmul (_ bv4294967293 32) arg0_3)))
(and (distinct ?x22800 (_ bv0 32)) true)))
(check-sat)
