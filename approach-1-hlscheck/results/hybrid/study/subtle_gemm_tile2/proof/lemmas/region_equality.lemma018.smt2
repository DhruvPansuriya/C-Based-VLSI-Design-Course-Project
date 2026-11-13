; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x20673 (bvmul arg0_11 arg1_12)))
(let ((?x525503 (bvmul (_ bv4294967295 32) ?x20673)))
(let ((?x353282 (bvmul arg0_11 arg1_13)))
(let ((?x488943 (bvadd ?x353282 ?x525503)))
(and (distinct ?x488943 (_ bv0 32)) true))))))
(check-sat)
