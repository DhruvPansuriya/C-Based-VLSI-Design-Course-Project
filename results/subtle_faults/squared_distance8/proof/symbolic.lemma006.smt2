; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_5 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x84119 (bvmul arg0_5 arg1_5)))
(let ((?x34552 (bvmul (_ bv4294967295 32) ?x84119)))
(and (distinct ?x34552 (_ bv0 32)) true))))
(check-sat)
