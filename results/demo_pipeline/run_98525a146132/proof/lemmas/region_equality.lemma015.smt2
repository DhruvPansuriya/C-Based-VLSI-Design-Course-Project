; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x7828 (bvmul (_ bv4294967295 32) arg1_3)))
(let ((?x155 (bvmul (_ bv4294967295 32) arg0_0)))
(let ((?x69 (bvmul arg0_0 arg1_3)))
(let ((?x942 (bvadd ?x69 ?x155 ?x7828)))
(and (distinct ?x942 (_ bv0 32)) true))))))
(check-sat)
