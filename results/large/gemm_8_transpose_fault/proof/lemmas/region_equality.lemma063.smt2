; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x75299 (bvmul arg0_9 arg1_1)))
(let ((?x4698 (bvmul (_ bv4294967295 32) ?x75299)))
(let ((?x1199 (bvmul arg0_9 arg1_8)))
(let ((?x69421 (bvadd ?x1199 ?x4698)))
(and (distinct ?x69421 (_ bv0 32)) true))))))
(check-sat)
