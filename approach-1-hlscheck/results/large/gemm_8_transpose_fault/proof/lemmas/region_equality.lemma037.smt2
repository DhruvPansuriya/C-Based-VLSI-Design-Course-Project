; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_41 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x73289 (bvmul arg0_1 arg1_41)))
(let ((?x68223 (bvmul (_ bv4294967295 32) ?x73289)))
(let ((?x5318 (bvmul arg0_1 arg1_13)))
(let ((?x73245 (bvadd ?x5318 ?x68223)))
(and (distinct ?x73245 (_ bv0 32)) true))))))
(check-sat)
