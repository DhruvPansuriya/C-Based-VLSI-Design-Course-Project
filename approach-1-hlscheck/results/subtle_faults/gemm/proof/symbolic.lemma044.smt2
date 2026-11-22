; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x179 (bvmul arg0_13 arg1_9)))
(let ((?x19256 (bvmul (_ bv4294967295 32) ?x179)))
(let ((?x65 (bvmul arg0_13 arg1_6)))
(let ((?x16634 (bvadd ?x65 ?x19256)))
(and (distinct ?x16634 (_ bv0 32)) true))))))
(check-sat)
