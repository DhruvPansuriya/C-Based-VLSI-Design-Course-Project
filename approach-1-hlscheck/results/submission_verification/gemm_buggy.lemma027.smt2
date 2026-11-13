; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x76 (bvmul arg0_9 arg1_1)))
(let ((?x147 (bvmul (_ bv4294967295 32) ?x76)))
(let ((?x208 (bvmul arg0_9 arg1_4)))
(let ((?x2387 (bvadd ?x208 ?x147)))
(and (distinct ?x2387 (_ bv0 32)) true))))))
(check-sat)
