; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x557372 ((_ extract 1 0) arg0_8)))
(let (($x1914 (= ?x557372 (_ bv3 2))))
(let ((?x386072 (ite $x1914 (_ bv1 32) (_ bv0 32))))
(let (($x10401 (= ?x557372 (_ bv2 2))))
(let ((?x365246 (ite $x10401 (_ bv1 32) (_ bv0 32))))
(let ((?x540877 (bvmul (_ bv4294967295 32) ?x365246)))
(let ((?x416188 (bvadd ?x540877 ?x386072)))
(and (distinct ?x416188 (_ bv0 32)) true)))))))))
(check-sat)
