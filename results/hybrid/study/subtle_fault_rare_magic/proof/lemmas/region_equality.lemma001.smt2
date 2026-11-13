; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let (($x155320 (= arg0 (_ bv3735928559 32))))
(let ((?x109504 (ite $x155320 arg0 (bvadd (_ bv1 32) arg0))))
(let ((?x586301 (bvmul (_ bv4294967295 32) ?x109504)))
(let ((?x93999 (bvadd arg0 ?x586301)))
(and (distinct ?x93999 (_ bv0 32)) true))))))
(check-sat)
