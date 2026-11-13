; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x543284 ((_ extract 1 0) arg0_14)))
(let (($x556536 (= ?x543284 (_ bv3 2))))
(let ((?x4093 (ite $x556536 (_ bv1 32) (_ bv0 32))))
(let (($x496115 (= ?x543284 (_ bv2 2))))
(let ((?x404287 (ite $x496115 (_ bv1 32) (_ bv0 32))))
(let ((?x538872 (bvmul (_ bv4294967295 32) ?x404287)))
(let ((?x10651 (bvadd ?x538872 ?x4093)))
(and (distinct ?x10651 (_ bv0 32)) true)))))))))
(check-sat)
