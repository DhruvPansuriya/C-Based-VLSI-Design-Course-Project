; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x413664 ((_ extract 1 0) arg0_1)))
(let (($x22849 (= ?x413664 (_ bv3 2))))
(let ((?x382219 (ite $x22849 (_ bv1 32) (_ bv0 32))))
(let (($x351485 (= ?x413664 (_ bv2 2))))
(let ((?x12966 (ite $x351485 (_ bv1 32) (_ bv0 32))))
(let ((?x354069 (bvmul (_ bv4294967295 32) ?x12966)))
(let ((?x380417 (bvadd ?x354069 ?x382219)))
(and (distinct ?x380417 (_ bv0 32)) true)))))))))
(check-sat)
