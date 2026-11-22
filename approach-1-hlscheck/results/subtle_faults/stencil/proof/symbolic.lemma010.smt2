; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x10573 (bvmul arg0_11 arg2_3)))
(let ((?x711464 (bvmul (_ bv4294967295 32) ?x10573)))
(let ((?x710 (bvmul arg0_11 arg2_4)))
(let ((?x711727 (bvadd ?x710 ?x711464)))
(and (distinct ?x711727 (_ bv0 32)) true))))))
(check-sat)
