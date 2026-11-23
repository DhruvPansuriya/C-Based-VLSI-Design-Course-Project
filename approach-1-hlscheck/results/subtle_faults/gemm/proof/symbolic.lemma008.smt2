; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x132 (bvmul arg0_1 arg1_9)))
(let ((?x310 (bvmul (_ bv4294967295 32) ?x132)))
(let ((?x10 (bvmul arg0_1 arg1_6)))
(let ((?x7798 (bvadd ?x10 ?x310)))
(and (distinct ?x7798 (_ bv0 32)) true))))))
(check-sat)
