; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x540426 (bvmul (_ bv4294967295 32) arg0_5)))
(and (distinct ?x540426 (_ bv0 32)) true)))
(check-sat)
