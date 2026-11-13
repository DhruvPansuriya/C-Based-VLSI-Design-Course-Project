; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x167 (bvmul arg0_9 arg1_1)))
(let ((?x17025 (bvmul (_ bv4294967295 32) ?x167)))
(let ((?x103 (bvmul arg0_9 arg1_4)))
(let ((?x13537 (bvadd ?x103 ?x17025)))
(and (distinct ?x13537 (_ bv0 32)) true))))))
(check-sat)
