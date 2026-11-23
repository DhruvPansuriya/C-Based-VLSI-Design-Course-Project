; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_16 () (_ BitVec 32))
(assert
 (let ((?x508983 (bvmul (_ bv2 32) arg0_16)))
(and (distinct ?x508983 (_ bv0 32)) true)))
(check-sat)
