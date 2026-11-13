; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x308931 ((_ extract 1 0) arg0_10)))
(let (($x509868 (= ?x308931 (_ bv3 2))))
(let ((?x408395 (ite $x509868 (_ bv1 32) (_ bv0 32))))
(let (($x684872 (= ?x308931 (_ bv2 2))))
(let ((?x611424 (ite $x684872 (_ bv1 32) (_ bv0 32))))
(let ((?x502888 (bvmul (_ bv4294967295 32) ?x611424)))
(let ((?x698409 (bvadd ?x502888 ?x408395)))
(and (distinct ?x698409 (_ bv0 32)) true)))))))))
(check-sat)
