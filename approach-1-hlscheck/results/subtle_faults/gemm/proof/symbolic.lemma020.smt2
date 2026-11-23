; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x150 (bvmul arg0_5 arg1_9)))
(let ((?x326 (bvmul (_ bv4294967295 32) ?x150)))
(let ((?x49 (bvmul arg0_5 arg1_6)))
(let ((?x9285 (bvadd ?x49 ?x326)))
(and (distinct ?x9285 (_ bv0 32)) true))))))
(check-sat)
