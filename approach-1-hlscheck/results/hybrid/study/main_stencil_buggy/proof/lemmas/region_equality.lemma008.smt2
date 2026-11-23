; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x41 (bvmul arg0_3 arg2_2)))
(let ((?x5034 (bvmul (_ bv4294967295 32) ?x41)))
(let ((?x18561 (bvmul arg0_3 arg2_1)))
(let ((?x727306 (bvadd ?x18561 ?x5034)))
(and (distinct ?x727306 (_ bv0 32)) true))))))
(check-sat)
