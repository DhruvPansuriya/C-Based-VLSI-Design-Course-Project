; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x182 (bvmul (_ bv4294967295 32) arg1_11)))
(let ((?x2072 (bvmul (_ bv4294967295 32) arg0_14)))
(let ((?x131 (bvmul arg0_14 arg1_11)))
(let ((?x2071 (bvadd ?x131 ?x2072 ?x182)))
(and (distinct ?x2071 (_ bv0 32)) true))))))
(check-sat)
