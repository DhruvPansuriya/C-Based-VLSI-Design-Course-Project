; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x473668 ((_ extract 1 0) arg0_13)))
(let (($x379848 (= ?x473668 (_ bv3 2))))
(let ((?x727367 (ite $x379848 (_ bv1 32) (_ bv0 32))))
(let (($x352564 (= ?x473668 (_ bv2 2))))
(let ((?x484156 (ite $x352564 (_ bv1 32) (_ bv0 32))))
(let ((?x353282 (bvmul (_ bv4294967295 32) ?x484156)))
(let ((?x699453 (bvadd ?x353282 ?x727367)))
(and (distinct ?x699453 (_ bv0 32)) true)))))))))
(check-sat)
