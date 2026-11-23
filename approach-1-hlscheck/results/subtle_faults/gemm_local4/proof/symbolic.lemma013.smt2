; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x380233 (bvmul arg0_12 arg1_2)))
(let ((?x353619 (bvmul (_ bv4294967295 32) ?x380233)))
(let ((?x23210 (bvmul arg0_12 arg1_3)))
(let ((?x381357 (bvadd ?x23210 ?x353619)))
(and (distinct ?x381357 (_ bv0 32)) true))))))
(check-sat)
