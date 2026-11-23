; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x145 (bvmul arg0_4 arg1_8)))
(let ((?x17364 (bvmul (_ bv4294967295 32) ?x145)))
(let ((?x82 (bvmul arg0_4 arg1_2)))
(let ((?x19030 (bvadd ?x82 ?x17364)))
(and (distinct ?x19030 (_ bv0 32)) true))))))
(check-sat)
