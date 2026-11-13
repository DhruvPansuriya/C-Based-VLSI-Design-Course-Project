; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x8516 (bvmul (_ bv4294967295 32) arg0_8)))
(and (distinct ?x8516 (_ bv0 32)) true)))
(check-sat)
