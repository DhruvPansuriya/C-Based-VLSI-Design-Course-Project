; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x21 (bvmul arg0_6 arg1_14)))
(let ((?x17446 (bvmul (_ bv4294967295 32) ?x21)))
(let ((?x156 (bvmul arg0_6 arg1_11)))
(let ((?x9874 (bvadd ?x156 ?x17446)))
(and (distinct ?x9874 (_ bv0 32)) true))))))
(check-sat)
