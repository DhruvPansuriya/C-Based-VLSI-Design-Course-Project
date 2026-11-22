; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x94 (bvmul arg0_17 arg2_3)))
(let ((?x731999 (bvmul (_ bv4294967295 32) ?x94)))
(let ((?x711025 (bvmul arg0_17 arg2_4)))
(let ((?x719695 (bvadd ?x711025 ?x731999)))
(and (distinct ?x719695 (_ bv0 32)) true))))))
(check-sat)
