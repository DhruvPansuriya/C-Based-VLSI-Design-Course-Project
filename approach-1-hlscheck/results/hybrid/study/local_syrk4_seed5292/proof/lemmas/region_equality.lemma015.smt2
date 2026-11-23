; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x399946 (bvmul arg0_6 arg0_8)))
(let ((?x431109 (bvmul (_ bv4294967295 32) ?x399946)))
(let ((?x359359 (bvmul arg0_2 arg0_6)))
(let ((?x358077 (bvadd ?x359359 ?x431109)))
(and (distinct ?x358077 (_ bv0 32)) true))))))
(check-sat)
