; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x2703 (bvmul (_ bv4294967295 32) arg1_13)))
(let ((?x158 (bvmul (_ bv4294967295 32) arg0_3)))
(let ((?x61 (bvmul arg0_3 arg1_13)))
(let ((?x165 (bvadd ?x61 ?x158 ?x2703)))
(and (distinct ?x165 (_ bv0 32)) true))))))
(check-sat)
