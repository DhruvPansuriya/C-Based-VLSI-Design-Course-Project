; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x166 (bvmul arg0_8 arg1_12)))
(let ((?x17373 (bvmul (_ bv4294967295 32) ?x166)))
(let ((?x380 (bvmul arg0_8 arg1_3)))
(let ((?x15680 (bvadd ?x380 ?x17373)))
(and (distinct ?x15680 (_ bv0 32)) true))))))
(check-sat)
