; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x519542 ((_ extract 1 0) arg0_8)))
(let (($x21399 (= ?x519542 (_ bv3 2))))
(let ((?x434957 (ite $x21399 (_ bv1 32) (_ bv0 32))))
(let (($x405745 (= ?x519542 (_ bv2 2))))
(let ((?x336346 (ite $x405745 (_ bv1 32) (_ bv0 32))))
(let ((?x29804 (bvmul (_ bv4294967295 32) ?x336346)))
(let ((?x451106 (bvadd ?x29804 ?x434957)))
(and (distinct ?x451106 (_ bv0 32)) true)))))))))
(check-sat)
