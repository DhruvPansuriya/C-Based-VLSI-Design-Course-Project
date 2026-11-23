; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x85 (bvmul arg0_2 arg1_14)))
(let ((?x10782 (bvmul (_ bv4294967295 32) ?x85)))
(let ((?x99 (bvmul arg0_2 arg1_11)))
(let ((?x20742 (bvadd ?x99 ?x10782)))
(and (distinct ?x20742 (_ bv0 32)) true))))))
(check-sat)
