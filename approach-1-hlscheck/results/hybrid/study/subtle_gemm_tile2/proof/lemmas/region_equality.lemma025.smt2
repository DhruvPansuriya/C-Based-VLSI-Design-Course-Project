; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x520853 (bvmul arg0_12 arg1_0)))
(let ((?x589027 (bvmul (_ bv4294967295 32) ?x520853)))
(let ((?x507632 (bvmul arg0_12 arg1_1)))
(let ((?x580863 (bvadd ?x507632 ?x589027)))
(and (distinct ?x580863 (_ bv0 32)) true))))))
(check-sat)
