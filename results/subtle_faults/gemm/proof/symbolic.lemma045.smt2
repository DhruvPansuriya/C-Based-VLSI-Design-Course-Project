; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x213 (bvmul arg0_15 arg1_11)))
(let ((?x9099 (bvmul (_ bv4294967295 32) ?x213)))
(let ((?x25 (bvmul arg0_15 arg1_14)))
(let ((?x4449 (bvadd ?x25 ?x9099)))
(and (distinct ?x4449 (_ bv0 32)) true))))))
(check-sat)
