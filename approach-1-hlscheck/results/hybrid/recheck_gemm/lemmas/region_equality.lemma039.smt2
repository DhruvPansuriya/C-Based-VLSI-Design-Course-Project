; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x190 (bvmul arg0_15 arg1_3)))
(let ((?x20189 (bvmul (_ bv4294967295 32) ?x190)))
(let ((?x115 (bvmul arg0_15 arg1_12)))
(let ((?x5516 (bvadd ?x115 ?x20189)))
(and (distinct ?x5516 (_ bv0 32)) true))))))
(check-sat)
