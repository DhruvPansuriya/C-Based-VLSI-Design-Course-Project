; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x336346 (bvmul (_ bv4294967295 32) arg0_10)))
(and (distinct ?x336346 (_ bv0 32)) true)))
(check-sat)
