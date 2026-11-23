; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_39 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg1_60 () (_ BitVec 32))
(assert
 (let ((?x72933 (bvmul arg0_23 arg1_39)))
(let ((?x55342 (bvmul (_ bv4294967295 32) ?x72933)))
(let ((?x63545 (bvmul arg0_23 arg1_60)))
(let ((?x75369 (bvadd ?x63545 ?x55342)))
(and (distinct ?x75369 (_ bv0 32)) true))))))
(check-sat)
