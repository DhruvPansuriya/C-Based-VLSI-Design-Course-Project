; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x15897 (bvmul arg0_0 arg1_2)))
(let ((?x405666 (bvmul (_ bv4294967295 32) ?x15897)))
(let ((?x7899 (bvmul arg0_0 arg1_3)))
(let ((?x379110 (bvadd ?x7899 ?x405666)))
(and (distinct ?x379110 (_ bv0 32)) true))))))
(check-sat)
