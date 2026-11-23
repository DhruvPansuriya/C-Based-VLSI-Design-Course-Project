; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x90 (bvmul arg0_10 arg1_14)))
(let ((?x11659 (bvmul (_ bv4294967295 32) ?x90)))
(let ((?x61 (bvmul arg0_10 arg1_11)))
(let ((?x1173 (bvadd ?x61 ?x11659)))
(and (distinct ?x1173 (_ bv0 32)) true))))))
(check-sat)
