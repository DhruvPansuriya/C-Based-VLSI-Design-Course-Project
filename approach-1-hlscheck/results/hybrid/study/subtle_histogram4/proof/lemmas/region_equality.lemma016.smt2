; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x29431 ((_ extract 1 0) arg0_9)))
(let (($x717120 (= ?x29431 (_ bv3 2))))
(let ((?x728472 (ite $x717120 (_ bv1 32) (_ bv0 32))))
(let (($x11570 (= ?x29431 (_ bv2 2))))
(let ((?x381146 (ite $x11570 (_ bv1 32) (_ bv0 32))))
(let ((?x401516 (bvmul (_ bv4294967295 32) ?x381146)))
(let ((?x489627 (bvadd ?x401516 ?x728472)))
(and (distinct ?x489627 (_ bv0 32)) true)))))))))
(check-sat)
