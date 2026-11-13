; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x46 (bvmul arg0_2 arg1_6)))
(let ((?x12377 (bvmul (_ bv4294967295 32) ?x46)))
(let ((?x73 (bvmul arg0_2 arg1_9)))
(let ((?x1090 (bvadd ?x73 ?x12377)))
(and (distinct ?x1090 (_ bv0 32)) true))))))
(check-sat)
