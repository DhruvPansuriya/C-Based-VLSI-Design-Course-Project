; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x90 (bvmul arg0_5 arg1_9)))
(let ((?x3003 (bvmul (_ bv4294967295 32) ?x90)))
(let ((?x15 (bvmul arg0_5 arg1_6)))
(let ((?x4534 (bvadd ?x15 ?x3003)))
(and (distinct ?x4534 (_ bv0 32)) true))))))
(check-sat)
