; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(declare-fun arg1 () (_ BitVec 32))
(assert
 (let ((?x201509 (ite (bvule arg0 arg1) arg1 arg0)))
(let ((?x565063 (ite (bvule arg1 arg0) arg0 arg1)))
(let ((?x19479 (bvmul (_ bv4294967295 32) ?x565063)))
(let (($x438339 (and (distinct (_ bv0 32) (bvadd ?x19479 ?x201509)) true)))
(let (($x436015 (and true true (or $x438339))))
(or $x436015)))))))
(check-sat)
