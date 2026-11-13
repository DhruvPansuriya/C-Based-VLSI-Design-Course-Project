; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x573131 (bvmul arg0_1 arg1_1)))
(let ((?x741933 (bvmul (_ bv4294967295 32) ?x573131)))
(and (distinct ?x741933 (_ bv0 32)) true))))
(check-sat)
