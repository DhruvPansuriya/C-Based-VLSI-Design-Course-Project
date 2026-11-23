; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x330645 (bvmul arg0_2 arg1_14)))
(let ((?x98622 (bvmul (_ bv4294967295 32) ?x330645)))
(let ((?x30428 (bvmul arg0_2 arg1_11)))
(let ((?x347018 (bvadd ?x30428 ?x98622)))
(and (distinct ?x347018 (_ bv0 32)) true))))))
(check-sat)
