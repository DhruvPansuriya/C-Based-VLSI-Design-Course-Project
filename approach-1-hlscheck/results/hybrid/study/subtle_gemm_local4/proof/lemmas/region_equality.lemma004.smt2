; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x54256 (bvmul arg0_3 arg1_14)))
(let ((?x380581 (bvmul (_ bv4294967295 32) ?x54256)))
(let ((?x382782 (bvmul arg0_3 arg1_15)))
(let ((?x22646 (bvadd ?x382782 ?x380581)))
(and (distinct ?x22646 (_ bv0 32)) true))))))
(check-sat)
