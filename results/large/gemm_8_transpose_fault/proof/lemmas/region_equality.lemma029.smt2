; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_32 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x73094 (bvmul arg0_0 arg1_32)))
(let ((?x65807 (bvmul (_ bv4294967295 32) ?x73094)))
(let ((?x33560 (bvmul arg0_0 arg1_4)))
(let ((?x75939 (bvadd ?x33560 ?x65807)))
(and (distinct ?x75939 (_ bv0 32)) true))))))
(check-sat)
