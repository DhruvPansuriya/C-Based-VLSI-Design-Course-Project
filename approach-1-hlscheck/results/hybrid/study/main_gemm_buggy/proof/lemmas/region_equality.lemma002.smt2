; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x180 (bvmul arg0_2 arg1_2)))
(let ((?x1869 (bvmul (_ bv4294967295 32) ?x180)))
(let ((?x26 (bvmul arg0_2 arg1_8)))
(let ((?x2217 (bvadd ?x26 ?x1869)))
(and (distinct ?x2217 (_ bv0 32)) true))))))
(check-sat)
