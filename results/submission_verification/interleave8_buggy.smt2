; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let (($x429434 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let ((?x509161 (concat ((_ extract 31 1) arg0_0) (bvnot ((_ extract 0 0) arg0_0)))))
(let ((?x421185 (bvmul (_ bv4294967295 32) ?x509161)))
(let ((?x487664 (bvadd arg0_0 ?x421185)))
(let (($x484576 (and (distinct (_ bv0 32) ?x487664) true)))
(let (($x438141 (or $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x484576 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434 $x429434)))
(let (($x478254 (and true true $x438141)))
(or $x478254)))))))))
(check-sat)
