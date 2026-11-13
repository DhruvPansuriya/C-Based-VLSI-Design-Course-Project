; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x162 (bvmul arg0_7 arg1_7)))
(let ((?x299 (bvmul (_ bv4294967295 32) ?x162)))
(let ((?x80 (bvmul arg0_7 arg1_13)))
(let ((?x16275 (bvadd ?x80 ?x299)))
(and (distinct ?x16275 (_ bv0 32)) true))))))
(check-sat)
