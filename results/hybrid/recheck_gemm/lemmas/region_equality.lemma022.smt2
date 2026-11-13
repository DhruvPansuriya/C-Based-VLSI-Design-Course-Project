; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x152 (bvmul arg0_4 arg1_12)))
(let ((?x8669 (bvmul (_ bv4294967295 32) ?x152)))
(let ((?x87 (bvmul arg0_4 arg1_3)))
(let ((?x20269 (bvadd ?x87 ?x8669)))
(and (distinct ?x20269 (_ bv0 32)) true))))))
(check-sat)
