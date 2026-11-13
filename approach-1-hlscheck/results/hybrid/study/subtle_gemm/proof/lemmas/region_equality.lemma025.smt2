; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x357396 (bvmul arg0_10 arg1_2)))
(let ((?x317809 (bvmul (_ bv4294967295 32) ?x357396)))
(let ((?x361917 (bvmul arg0_10 arg1_8)))
(let ((?x108588 (bvadd ?x361917 ?x317809)))
(and (distinct ?x108588 (_ bv0 32)) true))))))
(check-sat)
