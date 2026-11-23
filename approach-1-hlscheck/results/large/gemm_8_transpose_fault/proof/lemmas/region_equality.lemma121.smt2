; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg1_17 () (_ BitVec 32))
(assert
 (let ((?x72912 (bvmul arg0_18 arg1_10)))
(let ((?x60904 (bvmul (_ bv4294967295 32) ?x72912)))
(let ((?x5600 (bvmul arg0_18 arg1_17)))
(let ((?x67888 (bvadd ?x5600 ?x60904)))
(and (distinct ?x67888 (_ bv0 32)) true))))))
(check-sat)
