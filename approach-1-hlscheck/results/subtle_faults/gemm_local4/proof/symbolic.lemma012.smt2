; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x365179 (bvmul arg0_9 arg1_6)))
(let ((?x350823 (bvmul (_ bv4294967295 32) ?x365179)))
(let ((?x14498 (bvmul arg0_9 arg1_7)))
(let ((?x366498 (bvadd ?x14498 ?x350823)))
(and (distinct ?x366498 (_ bv0 32)) true))))))
(check-sat)
