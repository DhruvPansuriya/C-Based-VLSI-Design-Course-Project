; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let (($x727851 (= arg0_3 (_ bv0 32))))
(let ((?x385606 (ite $x727851 (_ bv0 32) (_ bv1 32))))
(let ((?x385187 (ite $x727851 (_ bv1 32) (_ bv0 32))))
(let ((?x30119 (bvmul (_ bv4294967295 32) ?x385187)))
(let ((?x383073 (bvadd ?x30119 ?x385606)))
(and (distinct ?x383073 (_ bv0 32)) true)))))))
(check-sat)
