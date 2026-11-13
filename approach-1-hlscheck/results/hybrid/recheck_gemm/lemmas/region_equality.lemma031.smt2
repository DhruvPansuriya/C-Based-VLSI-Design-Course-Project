; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x179 (bvmul arg0_11 arg1_11)))
(let ((?x1381 (bvmul (_ bv4294967295 32) ?x179)))
(let ((?x105 (bvmul arg0_11 arg1_14)))
(let ((?x19273 (bvadd ?x105 ?x1381)))
(and (distinct ?x19273 (_ bv0 32)) true))))))
(check-sat)
