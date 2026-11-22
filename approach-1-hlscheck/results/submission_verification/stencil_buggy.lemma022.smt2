; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x11223 (bvmul arg0_12 arg2_2)))
(let ((?x713060 (bvmul (_ bv4294967295 32) ?x11223)))
(let ((?x72 (bvmul arg0_12 arg2_1)))
(let ((?x381474 (bvadd ?x72 ?x713060)))
(and (distinct ?x381474 (_ bv0 32)) true))))))
(check-sat)
