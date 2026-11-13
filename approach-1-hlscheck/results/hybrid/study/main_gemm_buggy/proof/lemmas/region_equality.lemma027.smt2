; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x152 (bvmul arg0_9 arg1_1)))
(let ((?x10501 (bvmul (_ bv4294967295 32) ?x152)))
(let ((?x5058 (bvmul arg0_9 arg1_4)))
(let ((?x21260 (bvadd ?x5058 ?x10501)))
(and (distinct ?x21260 (_ bv0 32)) true))))))
(check-sat)
