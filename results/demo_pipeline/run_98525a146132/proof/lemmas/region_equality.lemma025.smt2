; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x171 (bvmul (_ bv4294967295 32) arg1_10)))
(let ((?x193 (bvmul (_ bv4294967295 32) arg0_6)))
(let ((?x87 (bvmul arg0_6 arg1_10)))
(let ((?x232 (bvadd ?x87 ?x193 ?x171)))
(and (distinct ?x232 (_ bv0 32)) true))))))
(check-sat)
