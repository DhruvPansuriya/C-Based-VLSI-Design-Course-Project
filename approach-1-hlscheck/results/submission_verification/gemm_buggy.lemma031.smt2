; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x116 (bvmul arg0_11 arg1_11)))
(let ((?x16577 (bvmul (_ bv4294967295 32) ?x116)))
(let ((?x169 (bvmul arg0_11 arg1_14)))
(let ((?x8679 (bvadd ?x169 ?x16577)))
(and (distinct ?x8679 (_ bv0 32)) true))))))
(check-sat)
