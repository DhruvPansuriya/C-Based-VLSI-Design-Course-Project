; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x4084 (bvmul (_ bv4294967295 32) arg1_15)))
(let ((?x9329 (bvmul (_ bv4294967295 32) arg0_11)))
(let ((?x111 (bvmul arg0_11 arg1_15)))
(let ((?x224 (bvadd ?x111 ?x9329 ?x4084)))
(and (distinct ?x224 (_ bv0 32)) true))))))
(check-sat)
