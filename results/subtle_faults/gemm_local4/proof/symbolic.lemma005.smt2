; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x735821 (bvmul arg0_4 arg1_2)))
(let ((?x369930 (bvmul (_ bv4294967295 32) ?x735821)))
(let ((?x380454 (bvmul arg0_4 arg1_3)))
(let ((?x380584 (bvadd ?x380454 ?x369930)))
(and (distinct ?x380584 (_ bv0 32)) true))))))
(check-sat)
