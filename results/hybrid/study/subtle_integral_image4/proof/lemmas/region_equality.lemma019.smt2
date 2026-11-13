; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x308887 (bvmul (_ bv4294967292 32) arg0_4)))
(and (distinct ?x308887 (_ bv0 32)) true)))
(check-sat)
