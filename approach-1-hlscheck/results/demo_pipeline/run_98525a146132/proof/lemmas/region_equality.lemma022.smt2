; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x2703 (bvmul (_ bv4294967295 32) arg1_13)))
(let ((?x185 (bvmul (_ bv4294967295 32) arg0_7)))
(let ((?x81 (bvmul arg0_7 arg1_13)))
(let ((?x246 (bvadd ?x81 ?x185 ?x2703)))
(and (distinct ?x246 (_ bv0 32)) true))))))
(check-sat)
