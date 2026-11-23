; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x182 (bvmul (_ bv4294967295 32) arg1_11)))
(let ((?x193 (bvmul (_ bv4294967295 32) arg0_6)))
(let ((?x92 (bvmul arg0_6 arg1_11)))
(let ((?x7397 (bvadd ?x92 ?x193 ?x182)))
(and (distinct ?x7397 (_ bv0 32)) true))))))
(check-sat)
