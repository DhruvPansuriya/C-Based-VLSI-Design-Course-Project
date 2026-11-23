; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x9853 (bvmul arg0_1 arg1_4)))
(let ((?x565063 (bvmul (_ bv4294967295 32) ?x9853)))
(let ((?x469307 (bvmul arg0_1 arg1_5)))
(let ((?x403351 (bvadd ?x469307 ?x565063)))
(and (distinct ?x403351 (_ bv0 32)) true))))))
(check-sat)
