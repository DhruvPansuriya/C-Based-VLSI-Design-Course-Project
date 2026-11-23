; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x383071 (bvmul arg0_3 arg1_3)))
(let ((?x368222 (bvmul (_ bv4294967295 32) ?x383071)))
(and (distinct ?x368222 (_ bv0 32)) true))))
(check-sat)
