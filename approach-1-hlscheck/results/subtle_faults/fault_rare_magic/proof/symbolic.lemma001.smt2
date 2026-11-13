; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let (($x454918 (= arg0 (_ bv3735928559 32))))
(let ((?x525049 (ite $x454918 arg0 (bvadd (_ bv1 32) arg0))))
(let ((?x529267 (bvmul (_ bv4294967295 32) ?x525049)))
(let ((?x483075 (bvadd arg0 ?x529267)))
(and (distinct ?x483075 (_ bv0 32)) true))))))
(check-sat)
