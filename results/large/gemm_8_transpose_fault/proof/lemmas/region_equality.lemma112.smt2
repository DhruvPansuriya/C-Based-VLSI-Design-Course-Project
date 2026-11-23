; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_57 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x63803 (bvmul arg0_9 arg1_57)))
(let ((?x59691 (bvmul (_ bv4294967295 32) ?x63803)))
(let ((?x63386 (bvmul arg0_9 arg1_15)))
(let ((?x72009 (bvadd ?x63386 ?x59691)))
(and (distinct ?x72009 (_ bv0 32)) true))))))
(check-sat)
