; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_28 () (_ BitVec 32))
(declare-fun arg1_32 () (_ BitVec 32))
(assert
 (let ((?x67483 (bvmul arg0_28 arg1_4)))
(let ((?x64023 (bvmul (_ bv4294967295 32) ?x67483)))
(let ((?x22478 (bvmul arg0_28 arg1_32)))
(let ((?x62488 (bvadd ?x22478 ?x64023)))
(and (distinct ?x62488 (_ bv0 32)) true))))))
(check-sat)
