; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_29 () (_ BitVec 32))
(declare-fun arg1_41 () (_ BitVec 32))
(assert
 (let ((?x67206 (bvmul arg0_29 arg1_13)))
(let ((?x56777 (bvmul (_ bv4294967295 32) ?x67206)))
(let ((?x33716 (bvmul arg0_29 arg1_41)))
(let ((?x68644 (bvadd ?x33716 ?x56777)))
(and (distinct ?x68644 (_ bv0 32)) true))))))
(check-sat)
