; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x58580 (bvmul (_ bv4294967280 32) arg0_0)))
(and (distinct ?x58580 (_ bv0 32)) true)))
(check-sat)
