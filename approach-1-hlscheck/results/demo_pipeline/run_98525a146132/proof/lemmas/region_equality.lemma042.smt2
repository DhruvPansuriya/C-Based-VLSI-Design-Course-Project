; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x1052 (bvmul (_ bv4294967295 32) arg1_14)))
(let ((?x9329 (bvmul (_ bv4294967295 32) arg0_11)))
(let ((?x106 (bvmul arg0_11 arg1_14)))
(let ((?x3326 (bvadd ?x106 ?x9329 ?x1052)))
(and (distinct ?x3326 (_ bv0 32)) true))))))
(check-sat)
