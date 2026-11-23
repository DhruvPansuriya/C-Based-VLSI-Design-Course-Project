; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x525049 (ite (= arg0 (_ bv3735928559 32)) arg0 (bvadd (_ bv1 32) arg0))))
(let ((?x529267 (bvmul (_ bv4294967295 32) ?x525049)))
(let ((?x366114 (bvadd (_ bv1 32) arg0 ?x529267)))
(let (($x546953 (and (distinct (_ bv0 32) ?x366114) true)))
(let (($x482879 (and true true (or $x546953))))
(or $x482879)))))))
(check-sat)
