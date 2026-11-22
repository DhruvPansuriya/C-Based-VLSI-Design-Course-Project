; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x85 (bvmul arg0_7 arg1_3)))
(let ((?x6174 (bvmul (_ bv4294967295 32) ?x85)))
(let ((?x186 (bvmul arg0_7 arg1_12)))
(let ((?x13250 (bvadd ?x186 ?x6174)))
(and (distinct ?x13250 (_ bv0 32)) true))))))
(check-sat)
