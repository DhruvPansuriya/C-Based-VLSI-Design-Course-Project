; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x7828 (bvmul (_ bv4294967295 32) arg1_3)))
(let ((?x154 (bvmul (_ bv4294967295 32) arg0_4)))
(let ((?x89 (bvmul arg0_4 arg1_3)))
(let ((?x7449 (bvadd ?x89 ?x154 ?x7828)))
(and (distinct ?x7449 (_ bv0 32)) true))))))
(check-sat)
