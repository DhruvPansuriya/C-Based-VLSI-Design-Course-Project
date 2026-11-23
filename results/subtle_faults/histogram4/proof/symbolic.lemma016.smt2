; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x354762 ((_ extract 1 0) arg0_9)))
(let (($x413408 (= ?x354762 (_ bv3 2))))
(let ((?x381826 (ite $x413408 (_ bv1 32) (_ bv0 32))))
(let (($x363367 (= ?x354762 (_ bv2 2))))
(let ((?x1747 (ite $x363367 (_ bv1 32) (_ bv0 32))))
(let ((?x354745 (bvmul (_ bv4294967295 32) ?x1747)))
(let ((?x538307 (bvadd ?x354745 ?x381826)))
(and (distinct ?x538307 (_ bv0 32)) true)))))))))
(check-sat)
