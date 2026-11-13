; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x380470 (bvmul arg0_8 arg1_2)))
(let ((?x488471 (bvmul (_ bv4294967295 32) ?x380470)))
(let ((?x354660 (bvmul arg0_8 arg1_3)))
(let ((?x478275 (bvadd ?x354660 ?x488471)))
(and (distinct ?x478275 (_ bv0 32)) true))))))
(check-sat)
