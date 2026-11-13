; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x152 (bvmul arg0_4 arg1_8)))
(let ((?x16451 (bvmul (_ bv4294967295 32) ?x152)))
(let ((?x79 (bvmul arg0_4 arg1_2)))
(let ((?x3249 (bvadd ?x79 ?x16451)))
(and (distinct ?x3249 (_ bv0 32)) true))))))
(check-sat)
