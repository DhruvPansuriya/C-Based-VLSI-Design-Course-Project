; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x2631 (bvmul arg0_14 arg1_14)))
(let ((?x21769 (bvmul (_ bv4294967295 32) ?x2631)))
(let ((?x15 (bvmul arg0_14 arg1_11)))
(let ((?x12542 (bvadd ?x15 ?x21769)))
(and (distinct ?x12542 (_ bv0 32)) true))))))
(check-sat)
