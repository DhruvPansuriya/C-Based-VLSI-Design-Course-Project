; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x176 (bvmul (_ bv4294967295 32) arg1_1)))
(let ((?x10459 (bvmul (_ bv4294967295 32) arg0_8)))
(let ((?x99 (bvmul arg0_8 arg1_1)))
(let ((?x7492 (bvadd ?x99 ?x10459 ?x176)))
(and (distinct ?x7492 (_ bv0 32)) true))))))
(check-sat)
