; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x153 (bvmul arg0_5 arg1_1)))
(let ((?x16677 (bvmul (_ bv4294967295 32) ?x153)))
(let ((?x73 (bvmul arg0_5 arg1_4)))
(let ((?x9220 (bvadd ?x73 ?x16677)))
(and (distinct ?x9220 (_ bv0 32)) true))))))
(check-sat)
