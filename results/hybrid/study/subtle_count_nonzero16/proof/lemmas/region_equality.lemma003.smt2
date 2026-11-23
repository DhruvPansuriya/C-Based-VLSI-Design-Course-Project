; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let (($x334553 (= arg0_3 (_ bv0 32))))
(let ((?x347018 (ite $x334553 (_ bv0 32) (_ bv1 32))))
(let ((?x93054 (ite $x334553 (_ bv1 32) (_ bv0 32))))
(let ((?x429277 (bvmul (_ bv4294967295 32) ?x93054)))
(let ((?x592310 (bvadd ?x429277 ?x347018)))
(and (distinct ?x592310 (_ bv0 32)) true)))))))
(check-sat)
