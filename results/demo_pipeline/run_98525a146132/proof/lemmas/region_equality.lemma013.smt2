; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x182 (bvmul (_ bv4294967295 32) arg1_11)))
(let ((?x157 (bvmul (_ bv4294967295 32) arg0_2)))
(let ((?x72 (bvmul arg0_2 arg1_11)))
(let ((?x8793 (bvadd ?x72 ?x157 ?x182)))
(and (distinct ?x8793 (_ bv0 32)) true))))))
(check-sat)
