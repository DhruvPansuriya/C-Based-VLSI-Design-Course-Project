; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x21392 ((_ extract 1 0) arg0_3)))
(let (($x417192 (= ?x21392 (_ bv3 2))))
(let ((?x16383 (ite $x417192 (_ bv1 32) (_ bv0 32))))
(let (($x55228 (= ?x21392 (_ bv2 2))))
(let ((?x412901 (ite $x55228 (_ bv1 32) (_ bv0 32))))
(let ((?x366498 (bvmul (_ bv4294967295 32) ?x412901)))
(let ((?x538727 (bvadd ?x366498 ?x16383)))
(and (distinct ?x538727 (_ bv0 32)) true)))))))))
(check-sat)
