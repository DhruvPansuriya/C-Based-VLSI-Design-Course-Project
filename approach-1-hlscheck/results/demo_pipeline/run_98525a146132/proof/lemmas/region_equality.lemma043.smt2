; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x172 (bvmul (_ bv4294967295 32) arg1_2)))
(let ((?x10459 (bvmul (_ bv4294967295 32) arg0_8)))
(let ((?x104 (bvmul arg0_8 arg1_2)))
(let ((?x179 (bvadd ?x104 ?x10459 ?x172)))
(and (distinct ?x179 (_ bv0 32)) true))))))
(check-sat)
