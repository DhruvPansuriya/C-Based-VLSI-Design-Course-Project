; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x109504 (ite (= arg0 (_ bv3735928559 32)) arg0 (bvadd (_ bv1 32) arg0))))
(let ((?x586301 (bvmul (_ bv4294967295 32) ?x109504)))
(let (($x500038 (and (distinct (_ bv0 32) (bvadd (_ bv1 32) arg0 ?x586301)) true)))
(let (($x462054 (and true true (or $x500038))))
(or $x462054))))))
(check-sat)
