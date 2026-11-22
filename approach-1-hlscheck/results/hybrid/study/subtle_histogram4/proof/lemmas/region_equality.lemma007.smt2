; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x331836 ((_ extract 1 0) arg0_14)))
(let (($x441621 (= ?x331836 (_ bv3 2))))
(let ((?x480268 (ite $x441621 (_ bv1 32) (_ bv0 32))))
(let (($x22800 (= ?x331836 (_ bv2 2))))
(let ((?x325383 (ite $x22800 (_ bv1 32) (_ bv0 32))))
(let ((?x411047 (bvmul (_ bv4294967295 32) ?x325383)))
(let ((?x479280 (bvadd ?x411047 ?x480268)))
(and (distinct ?x479280 (_ bv0 32)) true)))))))))
(check-sat)
