; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x332354 (bvmul arg0_0 arg1_12)))
(let ((?x311838 (bvmul (_ bv4294967295 32) ?x332354)))
(let ((?x377189 (bvmul arg0_0 arg1_3)))
(let ((?x508037 (bvadd ?x377189 ?x311838)))
(and (distinct ?x508037 (_ bv0 32)) true))))))
(check-sat)
