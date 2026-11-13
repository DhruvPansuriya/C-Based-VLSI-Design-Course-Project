; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x147 (bvmul arg0_7 arg2_2)))
(let ((?x329294 (bvmul (_ bv4294967295 32) ?x147)))
(let ((?x165 (bvmul arg0_7 arg2_1)))
(let ((?x8970 (bvadd ?x165 ?x329294)))
(and (distinct ?x8970 (_ bv0 32)) true))))))
(check-sat)
