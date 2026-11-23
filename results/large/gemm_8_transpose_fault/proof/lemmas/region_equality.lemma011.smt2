; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_33 () (_ BitVec 32))
(assert
 (let ((?x73085 (bvmul arg0_4 arg1_12)))
(let ((?x60172 (bvmul (_ bv4294967295 32) ?x73085)))
(let ((?x10392 (bvmul arg0_4 arg1_33)))
(let ((?x75862 (bvadd ?x10392 ?x60172)))
(and (distinct ?x75862 (_ bv0 32)) true))))))
(check-sat)
