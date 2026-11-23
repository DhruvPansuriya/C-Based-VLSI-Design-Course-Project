; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_16 () (_ BitVec 32))
(assert
 (let ((?x63859 (bvmul arg0_10 arg1_2)))
(let ((?x57264 (bvmul (_ bv4294967295 32) ?x63859)))
(let ((?x63549 (bvmul arg0_10 arg1_16)))
(let ((?x55787 (bvadd ?x63549 ?x57264)))
(and (distinct ?x55787 (_ bv0 32)) true))))))
(check-sat)
