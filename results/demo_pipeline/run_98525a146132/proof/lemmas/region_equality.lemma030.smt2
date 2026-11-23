; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x4084 (bvmul (_ bv4294967295 32) arg1_15)))
(let ((?x185 (bvmul (_ bv4294967295 32) arg0_7)))
(let ((?x91 (bvmul arg0_7 arg1_15)))
(let ((?x198 (bvadd ?x91 ?x185 ?x4084)))
(and (distinct ?x198 (_ bv0 32)) true))))))
(check-sat)
