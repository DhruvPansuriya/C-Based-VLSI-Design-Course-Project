; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x337284 (bvmul arg0_8 arg1_0)))
(let ((?x456081 (bvmul (_ bv4294967295 32) ?x337284)))
(let ((?x325383 (bvmul arg0_8 arg1_1)))
(let ((?x18195 (bvadd ?x325383 ?x456081)))
(and (distinct ?x18195 (_ bv0 32)) true))))))
(check-sat)
