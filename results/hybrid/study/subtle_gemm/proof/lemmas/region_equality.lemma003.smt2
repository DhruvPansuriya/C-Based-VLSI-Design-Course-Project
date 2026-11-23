; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x340421 (bvmul arg0_3 arg1_3)))
(let ((?x303213 (bvmul (_ bv4294967295 32) ?x340421)))
(let ((?x303993 (bvmul arg0_3 arg1_12)))
(let ((?x298555 (bvadd ?x303993 ?x303213)))
(and (distinct ?x298555 (_ bv0 32)) true))))))
(check-sat)
