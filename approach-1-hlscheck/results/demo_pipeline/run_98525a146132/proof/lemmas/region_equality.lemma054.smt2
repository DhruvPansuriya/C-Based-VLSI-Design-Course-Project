; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x2703 (bvmul (_ bv4294967295 32) arg1_13)))
(let ((?x7593 (bvmul (_ bv4294967295 32) arg0_15)))
(let ((?x121 (bvmul arg0_15 arg1_13)))
(let ((?x246 (bvadd ?x121 ?x7593 ?x2703)))
(and (distinct ?x246 (_ bv0 32)) true))))))
(check-sat)
