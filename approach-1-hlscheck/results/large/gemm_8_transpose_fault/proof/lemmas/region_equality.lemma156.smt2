; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_49 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x75213 (bvmul arg0_17 arg1_49)))
(let ((?x68310 (bvmul (_ bv4294967295 32) ?x75213)))
(let ((?x4837 (bvmul arg0_17 arg1_14)))
(let ((?x56285 (bvadd ?x4837 ?x68310)))
(and (distinct ?x56285 (_ bv0 32)) true))))))
(check-sat)
