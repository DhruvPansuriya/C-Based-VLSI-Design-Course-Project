; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let (($x616161 (= arg0_15 (_ bv0 32))))
(let ((?x41936 (ite $x616161 (_ bv0 32) (_ bv1 32))))
(let ((?x685764 (ite $x616161 (_ bv1 32) (_ bv0 32))))
(let ((?x563639 (bvmul (_ bv4294967295 32) ?x685764)))
(let ((?x382361 (bvadd ?x563639 ?x41936)))
(and (distinct ?x382361 (_ bv0 32)) true)))))))
(check-sat)
