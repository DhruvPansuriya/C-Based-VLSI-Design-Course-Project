; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x162 (bvmul (_ bv4294967295 32) arg1_8)))
(let ((?x2072 (bvmul (_ bv4294967295 32) arg0_14)))
(let ((?x117 (bvmul arg0_14 arg1_8)))
(let ((?x2716 (bvadd ?x117 ?x2072 ?x162)))
(and (distinct ?x2716 (_ bv0 32)) true))))))
(check-sat)
