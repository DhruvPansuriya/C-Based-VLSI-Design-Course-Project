; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x454834 (bvmul arg0_4 arg1_0)))
(let ((?x573455 (bvmul (_ bv4294967295 32) ?x454834)))
(let ((?x516026 (bvmul arg0_4 arg1_1)))
(let ((?x544303 (bvadd ?x516026 ?x573455)))
(and (distinct ?x544303 (_ bv0 32)) true))))))
(check-sat)
