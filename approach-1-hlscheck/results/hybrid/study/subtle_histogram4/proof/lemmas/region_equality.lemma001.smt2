; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x434896 ((_ extract 1 0) arg0_0)))
(let (($x706772 (= ?x434896 (_ bv3 2))))
(let ((?x699699 (ite $x706772 (_ bv1 32) (_ bv0 32))))
(let (($x741331 (= ?x434896 (_ bv2 2))))
(let ((?x470325 (ite $x741331 (_ bv1 32) (_ bv0 32))))
(let ((?x497872 (bvmul (_ bv4294967295 32) ?x470325)))
(let ((?x346363 (bvadd ?x497872 ?x699699)))
(and (distinct ?x346363 (_ bv0 32)) true)))))))))
(check-sat)
