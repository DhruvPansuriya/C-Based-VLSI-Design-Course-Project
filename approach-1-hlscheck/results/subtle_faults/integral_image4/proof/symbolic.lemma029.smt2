; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x380188 (bvmul (_ bv4294967272 32) arg0_4)))
(and (distinct ?x380188 (_ bv0 32)) true)))
(check-sat)
