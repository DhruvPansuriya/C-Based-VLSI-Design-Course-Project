; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x112 (bvmul arg0_23 arg2_8)))
(let ((?x717506 (bvmul (_ bv4294967295 32) ?x112)))
(let ((?x53 (bvmul arg0_23 arg2_7)))
(let ((?x728512 (bvadd ?x53 ?x717506)))
(and (distinct ?x728512 (_ bv0 32)) true))))))
(check-sat)
