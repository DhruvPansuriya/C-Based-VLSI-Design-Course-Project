; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x157 (bvmul arg0_7 arg1_3)))
(let ((?x221 (bvmul (_ bv4294967295 32) ?x157)))
(let ((?x78 (bvmul arg0_7 arg1_12)))
(let ((?x3670 (bvadd ?x78 ?x221)))
(and (distinct ?x3670 (_ bv0 32)) true))))))
(check-sat)
