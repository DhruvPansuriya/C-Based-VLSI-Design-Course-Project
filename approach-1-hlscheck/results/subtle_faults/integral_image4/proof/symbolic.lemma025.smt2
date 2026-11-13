; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x735533 (bvmul (_ bv4294967292 32) arg0_8)))
(and (distinct ?x735533 (_ bv0 32)) true)))
(check-sat)
