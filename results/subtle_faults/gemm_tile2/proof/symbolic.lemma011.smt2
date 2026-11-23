; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x397595 (bvmul arg0_6 arg1_8)))
(let ((?x16905 (bvmul (_ bv4294967295 32) ?x397595)))
(let ((?x368877 (bvmul arg0_6 arg1_9)))
(let ((?x487253 (bvadd ?x368877 ?x16905)))
(and (distinct ?x487253 (_ bv0 32)) true))))))
(check-sat)
