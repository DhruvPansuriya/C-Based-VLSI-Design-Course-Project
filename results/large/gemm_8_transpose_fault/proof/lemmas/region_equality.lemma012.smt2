; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_41 () (_ BitVec 32))
(assert
 (let ((?x75304 (bvmul arg0_5 arg1_13)))
(let ((?x63950 (bvmul (_ bv4294967295 32) ?x75304)))
(let ((?x63361 (bvmul arg0_5 arg1_41)))
(let ((?x53819 (bvadd ?x63361 ?x63950)))
(and (distinct ?x53819 (_ bv0 32)) true))))))
(check-sat)
