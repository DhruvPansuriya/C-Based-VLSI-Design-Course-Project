; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let (($x386861 (= arg0_15 (_ bv0 32))))
(let ((?x717865 (ite $x386861 (_ bv0 32) (_ bv1 32))))
(let ((?x384473 (ite $x386861 (_ bv1 32) (_ bv0 32))))
(let ((?x382641 (bvmul (_ bv4294967295 32) ?x384473)))
(let ((?x7131 (bvadd ?x382641 ?x717865)))
(and (distinct ?x7131 (_ bv0 32)) true)))))))
(check-sat)
