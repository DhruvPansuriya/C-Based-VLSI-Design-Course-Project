; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x54 (bvmul arg0_2 arg2_2)))
(let ((?x7270 (bvmul (_ bv4294967295 32) ?x54)))
(let ((?x1869 (bvmul arg0_2 arg2_1)))
(let ((?x715600 (bvadd ?x1869 ?x7270)))
(and (distinct ?x715600 (_ bv0 32)) true))))))
(check-sat)
