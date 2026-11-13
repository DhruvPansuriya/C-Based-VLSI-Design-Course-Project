; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x492425 (bvmul arg0_3 arg1_12)))
(let ((?x473823 (bvmul (_ bv4294967295 32) ?x492425)))
(let ((?x473050 (bvmul arg0_3 arg1_13)))
(let ((?x493371 (bvadd ?x473050 ?x473823)))
(and (distinct ?x493371 (_ bv0 32)) true))))))
(check-sat)
