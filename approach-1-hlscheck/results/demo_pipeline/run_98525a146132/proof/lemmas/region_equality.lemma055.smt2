; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_5 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x177 (bvmul (_ bv4294967295 32) arg1_5)))
(let ((?x8069 (bvmul (_ bv4294967295 32) arg0_13)))
(let ((?x118 (bvmul arg0_13 arg1_5)))
(let ((?x3977 (bvadd ?x118 ?x8069 ?x177)))
(and (distinct ?x3977 (_ bv0 32)) true))))))
(check-sat)
