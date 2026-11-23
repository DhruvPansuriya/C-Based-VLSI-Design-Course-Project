; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x347867 (bvmul arg0_3 arg2_0)))
(let ((?x381396 (bvmul (_ bv4294967295 32) ?x347867)))
(let ((?x347378 (bvmul arg0_3 arg2_1)))
(let ((?x309008 (bvadd ?x347378 ?x381396)))
(and (distinct ?x309008 (_ bv0 32)) true))))))
(check-sat)
