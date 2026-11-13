; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x330807 (bvmul arg0_0 arg1_2)))
(let ((?x325558 (bvmul (_ bv4294967295 32) ?x330807)))
(let ((?x308887 (bvmul arg0_0 arg1_3)))
(let ((?x521899 (bvadd ?x308887 ?x325558)))
(and (distinct ?x521899 (_ bv0 32)) true))))))
(check-sat)
