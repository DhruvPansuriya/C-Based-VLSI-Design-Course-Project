; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let (($x663176 (= arg0_11 (_ bv0 32))))
(let ((?x691120 (ite $x663176 (_ bv0 32) (_ bv1 32))))
(let ((?x381456 (ite $x663176 (_ bv1 32) (_ bv0 32))))
(let ((?x434459 (bvmul (_ bv4294967295 32) ?x381456)))
(let ((?x515431 (bvadd ?x434459 ?x691120)))
(and (distinct ?x515431 (_ bv0 32)) true)))))))
(check-sat)
