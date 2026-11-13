; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x132 (bvmul arg0_0 arg1_4)))
(let ((?x16502 (bvmul (_ bv4294967295 32) ?x132)))
(let ((?x57 (bvmul arg0_0 arg1_1)))
(let ((?x16503 (bvadd ?x57 ?x16502)))
(and (distinct ?x16503 (_ bv0 32)) true))))))
(check-sat)
