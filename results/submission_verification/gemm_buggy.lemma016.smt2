; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x221 (bvmul arg0_4 arg1_4)))
(let ((?x13555 (bvmul (_ bv4294967295 32) ?x221)))
(let ((?x179 (bvmul arg0_4 arg1_1)))
(let ((?x7507 (bvadd ?x179 ?x13555)))
(and (distinct ?x7507 (_ bv0 32)) true))))))
(check-sat)
