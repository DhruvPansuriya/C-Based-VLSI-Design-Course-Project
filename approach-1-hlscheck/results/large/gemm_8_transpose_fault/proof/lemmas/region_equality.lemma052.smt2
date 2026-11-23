; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_58 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_23 () (_ BitVec 32))
(assert
 (let ((?x75514 (bvmul arg0_2 arg1_58)))
(let ((?x65733 (bvmul (_ bv4294967295 32) ?x75514)))
(let ((?x33712 (bvmul arg0_2 arg1_23)))
(let ((?x68459 (bvadd ?x33712 ?x65733)))
(and (distinct ?x68459 (_ bv0 32)) true))))))
(check-sat)
