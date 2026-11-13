; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x313861 (bvmul (_ bv4294967284 32) arg0_1)))
(and (distinct ?x313861 (_ bv0 32)) true)))
(check-sat)
