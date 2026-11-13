; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x163 (bvmul arg0_13 arg1_1)))
(let ((?x69 (bvmul (_ bv4294967295 32) ?x163)))
(let ((?x5034 (bvmul arg0_13 arg1_4)))
(let ((?x7875 (bvadd ?x5034 ?x69)))
(and (distinct ?x7875 (_ bv0 32)) true))))))
(check-sat)
