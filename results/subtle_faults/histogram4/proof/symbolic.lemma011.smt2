; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x14710 ((_ extract 1 0) arg0_4)))
(let (($x410600 (= ?x14710 (_ bv3 2))))
(let ((?x381357 (ite $x410600 (_ bv1 32) (_ bv0 32))))
(let (($x352850 (= ?x14710 (_ bv2 2))))
(let ((?x735554 (ite $x352850 (_ bv1 32) (_ bv0 32))))
(let ((?x386703 (bvmul (_ bv4294967295 32) ?x735554)))
(let ((?x404569 (bvadd ?x386703 ?x381357)))
(and (distinct ?x404569 (_ bv0 32)) true)))))))))
(check-sat)
