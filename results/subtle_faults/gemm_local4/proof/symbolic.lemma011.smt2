; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x19275 (bvmul arg0_8 arg1_2)))
(let ((?x410585 (bvmul (_ bv4294967295 32) ?x19275)))
(let ((?x6594 (bvmul arg0_8 arg1_3)))
(let ((?x411107 (bvadd ?x6594 ?x410585)))
(and (distinct ?x411107 (_ bv0 32)) true))))))
(check-sat)
