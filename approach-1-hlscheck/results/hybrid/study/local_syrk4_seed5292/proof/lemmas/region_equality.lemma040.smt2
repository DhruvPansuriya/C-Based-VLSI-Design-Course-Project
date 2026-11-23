; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x492026 (bvmul arg0_1 arg0_12)))
(let ((?x427506 (bvmul (_ bv4294967295 32) ?x492026)))
(let ((?x731722 (bvmul arg0_12 arg0_4)))
(let ((?x412396 (bvadd ?x731722 ?x427506)))
(and (distinct ?x412396 (_ bv0 32)) true))))))
(check-sat)
