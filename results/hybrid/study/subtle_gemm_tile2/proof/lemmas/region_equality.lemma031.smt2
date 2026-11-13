; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x502367 (bvmul arg0_14 arg1_10)))
(let ((?x17911 (bvmul (_ bv4294967295 32) ?x502367)))
(let ((?x340728 (bvmul arg0_14 arg1_11)))
(let ((?x404248 (bvadd ?x340728 ?x17911)))
(and (distinct ?x404248 (_ bv0 32)) true))))))
(check-sat)
