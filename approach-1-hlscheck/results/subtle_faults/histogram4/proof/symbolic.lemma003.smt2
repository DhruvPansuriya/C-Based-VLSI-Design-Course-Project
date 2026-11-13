; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x4703 ((_ extract 1 0) arg0_10)))
(let (($x409871 (= ?x4703 (_ bv3 2))))
(let ((?x496026 (ite $x409871 (_ bv1 32) (_ bv0 32))))
(let (($x369653 (= ?x4703 (_ bv2 2))))
(let ((?x11155 (ite $x369653 (_ bv1 32) (_ bv0 32))))
(let ((?x538866 (bvmul (_ bv4294967295 32) ?x11155)))
(let ((?x557132 (bvadd ?x538866 ?x496026)))
(and (distinct ?x557132 (_ bv0 32)) true)))))))))
(check-sat)
