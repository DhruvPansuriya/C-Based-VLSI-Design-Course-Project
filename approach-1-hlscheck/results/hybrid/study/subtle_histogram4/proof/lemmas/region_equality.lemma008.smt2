; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x613335 ((_ extract 1 0) arg0_15)))
(let (($x393889 (= ?x613335 (_ bv3 2))))
(let ((?x518837 (ite $x393889 (_ bv1 32) (_ bv0 32))))
(let (($x683640 (= ?x613335 (_ bv2 2))))
(let ((?x9853 (ite $x683640 (_ bv1 32) (_ bv0 32))))
(let ((?x461210 (bvmul (_ bv4294967295 32) ?x9853)))
(let ((?x477878 (bvadd ?x461210 ?x518837)))
(and (distinct ?x477878 (_ bv0 32)) true)))))))))
(check-sat)
