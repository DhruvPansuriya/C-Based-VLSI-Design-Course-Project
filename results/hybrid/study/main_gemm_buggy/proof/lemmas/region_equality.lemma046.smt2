; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x119 (bvmul arg0_12 arg1_12)))
(let ((?x18315 (bvmul (_ bv4294967295 32) ?x119)))
(let ((?x5038 (bvmul arg0_12 arg1_3)))
(let ((?x984 (bvadd ?x5038 ?x18315)))
(and (distinct ?x984 (_ bv0 32)) true))))))
(check-sat)
