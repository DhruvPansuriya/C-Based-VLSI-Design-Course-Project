; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x709413 (bvmul arg0_6 arg2_2)))
(let ((?x181 (bvmul (_ bv4294967295 32) ?x709413)))
(let ((?x2609 (bvmul arg0_6 arg2_1)))
(let ((?x721828 (bvadd ?x2609 ?x181)))
(and (distinct ?x721828 (_ bv0 32)) true))))))
(check-sat)
