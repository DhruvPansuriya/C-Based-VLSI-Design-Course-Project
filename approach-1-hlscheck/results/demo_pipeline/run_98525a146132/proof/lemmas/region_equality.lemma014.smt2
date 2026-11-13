; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x4084 (bvmul (_ bv4294967295 32) arg1_15)))
(let ((?x158 (bvmul (_ bv4294967295 32) arg0_3)))
(let ((?x71 (bvmul arg0_3 arg1_15)))
(let ((?x228 (bvadd ?x71 ?x158 ?x4084)))
(and (distinct ?x228 (_ bv0 32)) true))))))
(check-sat)
