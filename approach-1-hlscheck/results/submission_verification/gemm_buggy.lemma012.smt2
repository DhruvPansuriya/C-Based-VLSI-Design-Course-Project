; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x2628 (bvmul arg0_2 arg1_14)))
(let ((?x9893 (bvmul (_ bv4294967295 32) ?x2628)))
(let ((?x73 (bvmul arg0_2 arg1_11)))
(let ((?x15325 (bvadd ?x73 ?x9893)))
(and (distinct ?x15325 (_ bv0 32)) true))))))
(check-sat)
