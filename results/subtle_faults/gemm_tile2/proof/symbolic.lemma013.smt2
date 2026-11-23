; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x417082 (bvmul arg0_4 arg1_2)))
(let ((?x423786 (bvmul (_ bv4294967295 32) ?x417082)))
(let ((?x735670 (bvmul arg0_4 arg1_3)))
(let ((?x480544 (bvadd ?x735670 ?x423786)))
(and (distinct ?x480544 (_ bv0 32)) true))))))
(check-sat)
