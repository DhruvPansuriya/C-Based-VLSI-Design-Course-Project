; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x61950 ((_ extract 1 0) arg0_13)))
(let (($x410585 (= ?x61950 (_ bv3 2))))
(let ((?x2215 (ite $x410585 (_ bv1 32) (_ bv0 32))))
(let (($x405055 (= ?x61950 (_ bv2 2))))
(let ((?x557327 (ite $x405055 (_ bv1 32) (_ bv0 32))))
(let ((?x403645 (bvmul (_ bv4294967295 32) ?x557327)))
(let ((?x557336 (bvadd ?x403645 ?x2215)))
(and (distinct ?x557336 (_ bv0 32)) true)))))))))
(check-sat)
