; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let (($x719816 (= arg0_11 (_ bv0 32))))
(let ((?x383372 (ite $x719816 (_ bv0 32) (_ bv1 32))))
(let ((?x387536 (ite $x719816 (_ bv1 32) (_ bv0 32))))
(let ((?x16202 (bvmul (_ bv4294967295 32) ?x387536)))
(let ((?x726499 (bvadd ?x16202 ?x383372)))
(and (distinct ?x726499 (_ bv0 32)) true)))))))
(check-sat)
