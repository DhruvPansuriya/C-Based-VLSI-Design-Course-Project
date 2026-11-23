; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x182 (bvmul arg0_12 arg1_12)))
(let ((?x15129 (bvmul (_ bv4294967295 32) ?x182)))
(let ((?x48 (bvmul arg0_12 arg1_3)))
(let ((?x20413 (bvadd ?x48 ?x15129)))
(and (distinct ?x20413 (_ bv0 32)) true))))))
(check-sat)
