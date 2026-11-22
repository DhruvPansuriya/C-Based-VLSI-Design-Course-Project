; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x498907 (bvmul arg0_5 arg0_7)))
(let ((?x416392 (bvmul (_ bv4294967295 32) ?x498907)))
(let ((?x356703 (bvmul arg0_13 arg0_5)))
(let ((?x475969 (bvadd ?x356703 ?x416392)))
(and (distinct ?x475969 (_ bv0 32)) true))))))
(check-sat)
