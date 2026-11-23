; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x176 (bvmul arg0_13 arg1_9)))
(let ((?x7507 (bvmul (_ bv4294967295 32) ?x176)))
(let ((?x6 (bvmul arg0_13 arg1_6)))
(let ((?x13796 (bvadd ?x6 ?x7507)))
(and (distinct ?x13796 (_ bv0 32)) true))))))
(check-sat)
