; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x2619 (bvmul arg0_0 arg1_12)))
(let ((?x13762 (bvmul (_ bv4294967295 32) ?x2619)))
(let ((?x172 (bvmul arg0_0 arg1_3)))
(let ((?x2607 (bvadd ?x172 ?x13762)))
(and (distinct ?x2607 (_ bv0 32)) true))))))
(check-sat)
