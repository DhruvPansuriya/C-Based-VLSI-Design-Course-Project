; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x20 (bvmul arg0_21 arg2_8)))
(let ((?x719507 (bvmul (_ bv4294967295 32) ?x20)))
(let ((?x100 (bvmul arg0_21 arg2_7)))
(let ((?x711596 (bvadd ?x100 ?x719507)))
(and (distinct ?x711596 (_ bv0 32)) true))))))
(check-sat)
