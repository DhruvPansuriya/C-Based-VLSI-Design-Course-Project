; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x175 (bvmul arg0_11 arg1_3)))
(let ((?x18724 (bvmul (_ bv4294967295 32) ?x175)))
(let ((?x95 (bvmul arg0_11 arg1_12)))
(let ((?x6795 (bvadd ?x95 ?x18724)))
(and (distinct ?x6795 (_ bv0 32)) true))))))
(check-sat)
