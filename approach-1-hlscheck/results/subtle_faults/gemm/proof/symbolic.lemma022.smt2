; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x146 (bvmul arg0_4 arg1_12)))
(let ((?x7580 (bvmul (_ bv4294967295 32) ?x146)))
(let ((?x16 (bvmul arg0_4 arg1_3)))
(let ((?x11946 (bvadd ?x16 ?x7580)))
(and (distinct ?x11946 (_ bv0 32)) true))))))
(check-sat)
