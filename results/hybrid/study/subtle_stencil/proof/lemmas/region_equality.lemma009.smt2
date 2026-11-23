; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x299106 (bvmul arg0_8 arg2_3)))
(let ((?x412644 (bvmul (_ bv4294967295 32) ?x299106)))
(let ((?x347608 (bvmul arg0_8 arg2_4)))
(let ((?x737893 (bvadd ?x347608 ?x412644)))
(and (distinct ?x737893 (_ bv0 32)) true))))))
(check-sat)
