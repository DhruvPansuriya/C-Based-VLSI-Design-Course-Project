; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x557319 ((_ extract 1 0) arg0_7)))
(let (($x52597 (= ?x557319 (_ bv3 2))))
(let ((?x475362 (ite $x52597 (_ bv1 32) (_ bv0 32))))
(let (($x396105 (= ?x557319 (_ bv2 2))))
(let ((?x385364 (ite $x396105 (_ bv1 32) (_ bv0 32))))
(let ((?x542345 (bvmul (_ bv4294967295 32) ?x385364)))
(let ((?x379130 (bvadd ?x542345 ?x475362)))
(and (distinct ?x379130 (_ bv0 32)) true)))))))))
(check-sat)
