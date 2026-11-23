; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_41 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x2539 (bvmul arg0_9 arg1_41)))
(let ((?x54666 (bvmul (_ bv4294967295 32) ?x2539)))
(let ((?x45164 (bvmul arg0_9 arg1_13)))
(let ((?x72094 (bvadd ?x45164 ?x54666)))
(and (distinct ?x72094 (_ bv0 32)) true))))))
(check-sat)
