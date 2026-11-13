; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x1052 (bvmul (_ bv4294967295 32) arg1_14)))
(let ((?x158 (bvmul (_ bv4294967295 32) arg0_3)))
(let ((?x66 (bvmul arg0_3 arg1_14)))
(let ((?x152 (bvadd ?x66 ?x158 ?x1052)))
(and (distinct ?x152 (_ bv0 32)) true))))))
(check-sat)
