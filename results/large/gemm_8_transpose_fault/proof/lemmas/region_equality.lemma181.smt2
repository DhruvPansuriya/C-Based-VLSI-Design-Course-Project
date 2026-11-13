; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_30 () (_ BitVec 32))
(declare-fun arg1_49 () (_ BitVec 32))
(assert
 (let ((?x67164 (bvmul arg0_30 arg1_14)))
(let ((?x75489 (bvmul (_ bv4294967295 32) ?x67164)))
(let ((?x2446 (bvmul arg0_30 arg1_49)))
(let ((?x69239 (bvadd ?x2446 ?x75489)))
(and (distinct ?x69239 (_ bv0 32)) true))))))
(check-sat)
