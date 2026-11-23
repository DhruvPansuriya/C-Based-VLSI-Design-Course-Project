; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x13 (bvmul arg0_22 arg2_8)))
(let ((?x711598 (bvmul (_ bv4294967295 32) ?x13)))
(let ((?x13038 (bvmul arg0_22 arg2_7)))
(let ((?x17445 (bvadd ?x13038 ?x711598)))
(and (distinct ?x17445 (_ bv0 32)) true))))))
(check-sat)
