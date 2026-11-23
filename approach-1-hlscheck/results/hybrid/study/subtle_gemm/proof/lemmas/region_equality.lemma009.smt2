; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x329526 (bvmul arg0_3 arg1_11)))
(let ((?x304043 (bvmul (_ bv4294967295 32) ?x329526)))
(let ((?x484752 (bvmul arg0_3 arg1_14)))
(let ((?x108474 (bvadd ?x484752 ?x304043)))
(and (distinct ?x108474 (_ bv0 32)) true))))))
(check-sat)
