; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x141 (bvmul arg0_2 arg1_14)))
(let ((?x5099 (bvmul (_ bv4294967295 32) ?x141)))
(let ((?x71 (bvmul arg0_2 arg1_11)))
(let ((?x21401 (bvadd ?x71 ?x5099)))
(and (distinct ?x21401 (_ bv0 32)) true))))))
(check-sat)
