; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x354410 (bvmul arg0_13 arg1_4)))
(let ((?x487253 (bvmul (_ bv4294967295 32) ?x354410)))
(let ((?x386703 (bvmul arg0_13 arg1_5)))
(let ((?x490256 (bvadd ?x386703 ?x487253)))
(and (distinct ?x490256 (_ bv0 32)) true))))))
(check-sat)
