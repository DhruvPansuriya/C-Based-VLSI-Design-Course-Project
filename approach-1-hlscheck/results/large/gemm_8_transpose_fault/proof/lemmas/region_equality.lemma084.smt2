; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_25 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x63320 (bvmul arg0_9 arg1_25)))
(let ((?x45142 (bvmul (_ bv4294967295 32) ?x63320)))
(let ((?x3924 (bvmul arg0_9 arg1_11)))
(let ((?x72849 (bvadd ?x3924 ?x45142)))
(and (distinct ?x72849 (_ bv0 32)) true))))))
(check-sat)
