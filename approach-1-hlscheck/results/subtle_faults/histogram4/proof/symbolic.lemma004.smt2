; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x355164 ((_ extract 1 0) arg0_11)))
(let (($x387394 (= ?x355164 (_ bv3 2))))
(let ((?x398303 (ite $x387394 (_ bv1 32) (_ bv0 32))))
(let (($x538737 (= ?x355164 (_ bv2 2))))
(let ((?x14844 (ite $x538737 (_ bv1 32) (_ bv0 32))))
(let ((?x6594 (bvmul (_ bv4294967295 32) ?x14844)))
(let ((?x538725 (bvadd ?x6594 ?x398303)))
(and (distinct ?x538725 (_ bv0 32)) true)))))))))
(check-sat)
