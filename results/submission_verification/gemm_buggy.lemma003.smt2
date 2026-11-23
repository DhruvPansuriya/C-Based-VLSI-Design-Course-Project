; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x2624 (bvmul arg0_3 arg1_3)))
(let ((?x120 (bvmul (_ bv4294967295 32) ?x2624)))
(let ((?x50 (bvmul arg0_3 arg1_12)))
(let ((?x5586 (bvadd ?x50 ?x120)))
(and (distinct ?x5586 (_ bv0 32)) true))))))
(check-sat)
