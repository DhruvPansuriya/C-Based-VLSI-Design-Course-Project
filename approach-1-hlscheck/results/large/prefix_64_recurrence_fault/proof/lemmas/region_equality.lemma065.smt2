; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x75343 (bvmul (_ bv4294967286 32) arg0_0)))
(and (distinct ?x75343 (_ bv0 32)) true)))
(check-sat)
