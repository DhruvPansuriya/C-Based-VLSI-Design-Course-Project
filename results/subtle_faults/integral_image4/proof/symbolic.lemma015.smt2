; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x379429 (bvmul (_ bv4294967292 32) arg0_2)))
(and (distinct ?x379429 (_ bv0 32)) true)))
(check-sat)
