; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x172 (bvmul (_ bv4294967295 32) arg1_2)))
(let ((?x7274 (bvmul (_ bv4294967295 32) arg0_12)))
(let ((?x124 (bvmul arg0_12 arg1_2)))
(let ((?x10857 (bvadd ?x124 ?x7274 ?x172)))
(and (distinct ?x10857 (_ bv0 32)) true))))))
(check-sat)
