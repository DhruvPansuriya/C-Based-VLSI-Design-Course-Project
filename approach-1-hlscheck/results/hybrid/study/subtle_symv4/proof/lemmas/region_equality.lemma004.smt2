; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x684771 (bvmul arg0_0 arg1_0)))
(let ((?x469383 (bvmul (_ bv4294967295 32) ?x684771)))
(and (distinct ?x469383 (_ bv0 32)) true))))
(check-sat)
