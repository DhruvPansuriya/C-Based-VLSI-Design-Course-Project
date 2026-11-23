; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x15572 ((_ extract 1 0) arg0_11)))
(let (($x704580 (= ?x15572 (_ bv3 2))))
(let ((?x704269 (ite $x704580 (_ bv1 32) (_ bv0 32))))
(let (($x726912 (= ?x15572 (_ bv2 2))))
(let ((?x14631 (ite $x726912 (_ bv1 32) (_ bv0 32))))
(let ((?x512213 (bvmul (_ bv4294967295 32) ?x14631)))
(let ((?x406559 (bvadd ?x512213 ?x704269)))
(and (distinct ?x406559 (_ bv0 32)) true)))))))))
(check-sat)
