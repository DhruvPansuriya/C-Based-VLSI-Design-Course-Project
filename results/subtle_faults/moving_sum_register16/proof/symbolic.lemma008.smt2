; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x372285 (bvmul (_ bv4294967295 32) arg0_6)))
(and (distinct ?x372285 (_ bv0 32)) true)))
(check-sat)
