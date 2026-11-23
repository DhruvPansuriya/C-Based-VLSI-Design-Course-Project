; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x160 (bvmul (_ bv4294967295 32) arg1_12)))
(let ((?x185 (bvmul (_ bv4294967295 32) arg0_7)))
(let ((?x76 (bvmul arg0_7 arg1_12)))
(let ((?x5351 (bvadd ?x76 ?x185 ?x160)))
(and (distinct ?x5351 (_ bv0 32)) true))))))
(check-sat)
