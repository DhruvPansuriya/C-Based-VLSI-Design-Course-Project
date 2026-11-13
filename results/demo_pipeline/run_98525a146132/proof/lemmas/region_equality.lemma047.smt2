; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x7828 (bvmul (_ bv4294967295 32) arg1_3)))
(let ((?x10459 (bvmul (_ bv4294967295 32) arg0_8)))
(let ((?x109 (bvmul arg0_8 arg1_3)))
(let ((?x7449 (bvadd ?x109 ?x10459 ?x7828)))
(and (distinct ?x7449 (_ bv0 32)) true))))))
(check-sat)
