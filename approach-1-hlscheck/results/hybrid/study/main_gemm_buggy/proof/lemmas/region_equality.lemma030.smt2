; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x219 (bvmul arg0_8 arg1_4)))
(let ((?x6118 (bvmul (_ bv4294967295 32) ?x219)))
(let ((?x179 (bvmul arg0_8 arg1_1)))
(let ((?x21310 (bvadd ?x179 ?x6118)))
(and (distinct ?x21310 (_ bv0 32)) true))))))
(check-sat)
