; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_49 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x63372 (bvmul arg0_9 arg1_49)))
(let ((?x58407 (bvmul (_ bv4294967295 32) ?x63372)))
(let ((?x10672 (bvmul arg0_9 arg1_14)))
(let ((?x60575 (bvadd ?x10672 ?x58407)))
(and (distinct ?x60575 (_ bv0 32)) true))))))
(check-sat)
