; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x114 (bvmul arg0_8 arg1_8)))
(let ((?x12799 (bvmul (_ bv4294967295 32) ?x114)))
(let ((?x113 (bvmul arg0_8 arg1_2)))
(let ((?x6454 (bvadd ?x113 ?x12799)))
(and (distinct ?x6454 (_ bv0 32)) true))))))
(check-sat)
