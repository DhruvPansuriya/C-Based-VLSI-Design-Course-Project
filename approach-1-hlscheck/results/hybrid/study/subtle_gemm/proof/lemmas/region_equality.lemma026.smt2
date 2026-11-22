; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x29658 (bvmul arg0_11 arg1_3)))
(let ((?x336855 (bvmul (_ bv4294967295 32) ?x29658)))
(let ((?x340432 (bvmul arg0_11 arg1_12)))
(let ((?x304672 (bvadd ?x340432 ?x336855)))
(and (distinct ?x304672 (_ bv0 32)) true))))))
(check-sat)
