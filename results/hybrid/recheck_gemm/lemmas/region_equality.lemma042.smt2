; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x193 (bvmul arg0_15 arg1_7)))
(let ((?x10619 (bvmul (_ bv4294967295 32) ?x193)))
(let ((?x120 (bvmul arg0_15 arg1_13)))
(let ((?x17940 (bvadd ?x120 ?x10619)))
(and (distinct ?x17940 (_ bv0 32)) true))))))
(check-sat)
