; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_17 () (_ BitVec 32))
(assert
 (let ((?x510082 (bvmul (_ bv2 32) arg0_17)))
(and (distinct ?x510082 (_ bv0 32)) true)))
(check-sat)
