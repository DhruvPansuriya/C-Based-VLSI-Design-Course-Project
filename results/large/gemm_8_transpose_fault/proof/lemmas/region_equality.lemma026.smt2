; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_29 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_43 () (_ BitVec 32))
(assert
 (let ((?x75518 (bvmul arg0_5 arg1_29)))
(let ((?x60720 (bvmul (_ bv4294967295 32) ?x75518)))
(let ((?x3516 (bvmul arg0_5 arg1_43)))
(let ((?x58562 (bvadd ?x3516 ?x60720)))
(and (distinct ?x58562 (_ bv0 32)) true))))))
(check-sat)
