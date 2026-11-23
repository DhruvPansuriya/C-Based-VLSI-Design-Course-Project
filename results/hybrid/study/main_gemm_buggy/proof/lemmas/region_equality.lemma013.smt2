; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x2059 (bvmul arg0_5 arg1_1)))
(let ((?x11707 (bvmul (_ bv4294967295 32) ?x2059)))
(let ((?x5041 (bvmul arg0_5 arg1_4)))
(let ((?x16062 (bvadd ?x5041 ?x11707)))
(and (distinct ?x16062 (_ bv0 32)) true))))))
(check-sat)
