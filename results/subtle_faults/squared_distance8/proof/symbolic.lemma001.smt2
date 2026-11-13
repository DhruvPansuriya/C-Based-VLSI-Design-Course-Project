; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x367504 (bvmul arg0_0 arg1_0)))
(let ((?x369164 (bvmul (_ bv4294967295 32) ?x367504)))
(and (distinct ?x369164 (_ bv0 32)) true))))
(check-sat)
