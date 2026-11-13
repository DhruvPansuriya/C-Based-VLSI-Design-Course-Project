; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x2626 (bvmul arg0_2 arg1_2)))
(let ((?x180 (bvmul (_ bv4294967295 32) ?x2626)))
(let ((?x141 (bvmul arg0_2 arg1_8)))
(let ((?x5114 (bvadd ?x141 ?x180)))
(and (distinct ?x5114 (_ bv0 32)) true))))))
(check-sat)
