; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x360528 (bvmul arg0_10 arg0_11)))
(let ((?x149544 (bvmul (_ bv4294967295 32) ?x360528)))
(let ((?x501656 (bvmul arg0_10 arg0_14)))
(let ((?x412396 (bvadd ?x501656 ?x149544)))
(and (distinct ?x412396 (_ bv0 32)) true))))))
(check-sat)
