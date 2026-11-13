; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x103 (bvmul arg0_13 arg0_6)))
(let ((?x28824 (bvmul (_ bv4294967295 32) ?x103)))
(let ((?x1302 (bvmul arg0_13 arg0_9)))
(let ((?x12387 (bvadd ?x1302 ?x28824)))
(and (distinct ?x12387 (_ bv0 32)) true))))))
(check-sat)
