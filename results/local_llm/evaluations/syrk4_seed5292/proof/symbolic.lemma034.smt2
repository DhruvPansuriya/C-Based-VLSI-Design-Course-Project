; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x59 (bvmul arg0_10 arg0_11)))
(let ((?x6361 (bvmul (_ bv4294967295 32) ?x59)))
(let ((?x1121 (bvmul arg0_10 arg0_14)))
(let ((?x33398 (bvadd ?x1121 ?x6361)))
(and (distinct ?x33398 (_ bv0 32)) true))))))
(check-sat)
