; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x160 (bvmul (_ bv4294967295 32) arg1_12)))
(let ((?x9329 (bvmul (_ bv4294967295 32) arg0_11)))
(let ((?x96 (bvmul arg0_11 arg1_12)))
(let ((?x8793 (bvadd ?x96 ?x9329 ?x160)))
(and (distinct ?x8793 (_ bv0 32)) true))))))
(check-sat)
