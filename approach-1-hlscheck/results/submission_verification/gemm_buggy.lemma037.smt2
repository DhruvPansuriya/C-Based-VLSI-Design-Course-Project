; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x209 (bvmul arg0_13 arg1_1)))
(let ((?x12968 (bvmul (_ bv4294967295 32) ?x209)))
(let ((?x86 (bvmul arg0_13 arg1_4)))
(let ((?x15345 (bvadd ?x86 ?x12968)))
(and (distinct ?x15345 (_ bv0 32)) true))))))
(check-sat)
