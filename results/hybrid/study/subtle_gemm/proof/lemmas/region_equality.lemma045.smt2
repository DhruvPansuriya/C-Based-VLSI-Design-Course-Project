; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x293619 (bvmul arg0_15 arg1_11)))
(let ((?x303616 (bvmul (_ bv4294967295 32) ?x293619)))
(let ((?x527498 (bvmul arg0_15 arg1_14)))
(let ((?x339487 (bvadd ?x527498 ?x303616)))
(and (distinct ?x339487 (_ bv0 32)) true))))))
(check-sat)
