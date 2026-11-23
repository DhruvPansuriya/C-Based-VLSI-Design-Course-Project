; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x171 (bvmul (_ bv4294967295 32) arg1_10)))
(let ((?x152 (bvmul (_ bv4294967295 32) arg0_10)))
(let ((?x107 (bvmul arg0_10 arg1_10)))
(let ((?x10098 (bvadd ?x107 ?x152 ?x171)))
(and (distinct ?x10098 (_ bv0 32)) true))))))
(check-sat)
