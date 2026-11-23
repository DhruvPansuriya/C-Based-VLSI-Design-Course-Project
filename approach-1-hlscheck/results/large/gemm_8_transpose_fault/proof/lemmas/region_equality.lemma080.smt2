; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_29 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_43 () (_ BitVec 32))
(assert
 (let ((?x8387 (bvmul arg0_13 arg1_29)))
(let ((?x54656 (bvmul (_ bv4294967295 32) ?x8387)))
(let ((?x13606 (bvmul arg0_13 arg1_43)))
(let ((?x54564 (bvadd ?x13606 ?x54656)))
(and (distinct ?x54564 (_ bv0 32)) true))))))
(check-sat)
