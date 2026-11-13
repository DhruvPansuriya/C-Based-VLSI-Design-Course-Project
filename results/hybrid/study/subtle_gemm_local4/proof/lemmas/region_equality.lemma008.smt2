; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x12128 (bvmul arg0_7 arg1_14)))
(let ((?x10295 (bvmul (_ bv4294967295 32) ?x12128)))
(let ((?x522312 (bvmul arg0_7 arg1_15)))
(let ((?x647217 (bvadd ?x522312 ?x10295)))
(and (distinct ?x647217 (_ bv0 32)) true))))))
(check-sat)
