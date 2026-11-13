; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x69 (bvmul arg0_13 arg2_3)))
(let ((?x711253 (bvmul (_ bv4294967295 32) ?x69)))
(let ((?x123 (bvmul arg0_13 arg2_4)))
(let ((?x711727 (bvadd ?x123 ?x711253)))
(and (distinct ?x711727 (_ bv0 32)) true))))))
(check-sat)
