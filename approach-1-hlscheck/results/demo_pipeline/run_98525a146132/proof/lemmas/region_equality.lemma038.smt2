; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x2703 (bvmul (_ bv4294967295 32) arg1_13)))
(let ((?x9329 (bvmul (_ bv4294967295 32) arg0_11)))
(let ((?x101 (bvmul arg0_11 arg1_13)))
(let ((?x239 (bvadd ?x101 ?x9329 ?x2703)))
(and (distinct ?x239 (_ bv0 32)) true))))))
(check-sat)
