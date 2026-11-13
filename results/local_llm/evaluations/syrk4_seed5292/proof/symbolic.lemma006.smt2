; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x4038 (bvmul arg0_2 arg0_9)))
(let ((?x119 (bvmul (_ bv4294967295 32) ?x4038)))
(let ((?x736 (bvmul arg0_2 arg0_6)))
(let ((?x4434 (bvadd ?x736 ?x119)))
(and (distinct ?x4434 (_ bv0 32)) true))))))
(check-sat)
