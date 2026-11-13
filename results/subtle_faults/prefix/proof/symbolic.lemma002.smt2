; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x714697 (bvmul (_ bv4294967295 32) arg0_0)))
(and (distinct ?x714697 (_ bv0 32)) true)))
(check-sat)
