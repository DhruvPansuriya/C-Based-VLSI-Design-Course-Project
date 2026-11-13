; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x2995 (bvmul arg0_9 arg1_9)))
(let ((?x10808 (bvmul (_ bv4294967295 32) ?x2995)))
(let ((?x2030 (bvmul arg0_9 arg1_6)))
(let ((?x5680 (bvadd ?x2030 ?x10808)))
(and (distinct ?x5680 (_ bv0 32)) true))))))
(check-sat)
