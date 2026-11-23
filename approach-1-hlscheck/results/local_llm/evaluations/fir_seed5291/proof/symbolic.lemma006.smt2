; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x31 (bvmul (_ bv4294967284 32) arg0_7)))
(and (distinct ?x31 (_ bv0 32)) true)))
(check-sat)
