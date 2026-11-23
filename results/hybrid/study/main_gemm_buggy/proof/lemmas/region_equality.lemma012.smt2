; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x164 (bvmul arg0_2 arg1_14)))
(let ((?x10505 (bvmul (_ bv4294967295 32) ?x164)))
(let ((?x1900 (bvmul arg0_2 arg1_11)))
(let ((?x3256 (bvadd ?x1900 ?x10505)))
(and (distinct ?x3256 (_ bv0 32)) true))))))
(check-sat)
