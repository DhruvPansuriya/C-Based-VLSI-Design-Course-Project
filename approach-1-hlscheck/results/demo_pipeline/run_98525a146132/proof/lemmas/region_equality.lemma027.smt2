; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x172 (bvmul (_ bv4294967295 32) arg1_2)))
(let ((?x154 (bvmul (_ bv4294967295 32) arg0_4)))
(let ((?x84 (bvmul arg0_4 arg1_2)))
(let ((?x239 (bvadd ?x84 ?x154 ?x172)))
(and (distinct ?x239 (_ bv0 32)) true))))))
(check-sat)
