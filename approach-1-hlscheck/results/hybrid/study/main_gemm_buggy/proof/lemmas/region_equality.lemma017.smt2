; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x94 (bvmul arg0_6 arg1_6)))
(let ((?x6772 (bvmul (_ bv4294967295 32) ?x94)))
(let ((?x3479 (bvmul arg0_6 arg1_9)))
(let ((?x5114 (bvadd ?x3479 ?x6772)))
(and (distinct ?x5114 (_ bv0 32)) true))))))
(check-sat)
