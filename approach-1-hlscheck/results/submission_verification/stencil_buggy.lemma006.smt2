; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x180 (bvmul arg0_7 arg2_5)))
(let ((?x8679 (bvmul (_ bv4294967295 32) ?x180)))
(let ((?x229 (bvmul arg0_7 arg2_4)))
(let ((?x710336 (bvadd ?x229 ?x8679)))
(and (distinct ?x710336 (_ bv0 32)) true))))))
(check-sat)
