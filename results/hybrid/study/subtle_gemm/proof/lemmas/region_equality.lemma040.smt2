; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x303628 (bvmul arg0_12 arg1_4)))
(let ((?x336146 (bvmul (_ bv4294967295 32) ?x303628)))
(let ((?x340311 (bvmul arg0_12 arg1_1)))
(let ((?x311470 (bvadd ?x340311 ?x336146)))
(and (distinct ?x311470 (_ bv0 32)) true))))))
(check-sat)
