; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x61 (bvmul arg0_15 arg1_3)))
(let ((?x7549 (bvmul (_ bv4294967295 32) ?x61)))
(let ((?x3493 (bvmul arg0_15 arg1_12)))
(let ((?x7270 (bvadd ?x3493 ?x7549)))
(and (distinct ?x7270 (_ bv0 32)) true))))))
(check-sat)
