; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x14631 (bvmul arg0_3 arg1_3)))
(let ((?x303392 (bvmul (_ bv4294967295 32) ?x14631)))
(and (distinct ?x303392 (_ bv0 32)) true))))
(check-sat)
