; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x4084 (bvmul (_ bv4294967295 32) arg1_15)))
(let ((?x7593 (bvmul (_ bv4294967295 32) arg0_15)))
(let ((?x128 (bvmul arg0_15 arg1_15)))
(let ((?x9628 (bvadd ?x128 ?x7593 ?x4084)))
(and (distinct ?x9628 (_ bv0 32)) true))))))
(check-sat)
