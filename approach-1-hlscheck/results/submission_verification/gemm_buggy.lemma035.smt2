; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x175 (bvmul arg0_8 arg1_12)))
(let ((?x7267 (bvmul (_ bv4294967295 32) ?x175)))
(let ((?x218 (bvmul arg0_8 arg1_3)))
(let ((?x21758 (bvadd ?x218 ?x7267)))
(and (distinct ?x21758 (_ bv0 32)) true))))))
(check-sat)
