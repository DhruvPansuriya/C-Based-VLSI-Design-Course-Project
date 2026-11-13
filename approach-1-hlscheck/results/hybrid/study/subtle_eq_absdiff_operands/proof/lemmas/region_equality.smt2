; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x436015 (bvadd arg0 (bvmul (_ bv4294967295 32) arg1))))
(let ((?x586464 (bvmul (_ bv4294967295 32) arg0)))
(let ((?x380121 (bvadd arg1 ?x586464)))
(let (($x585762 (bvule arg0 arg1)))
(let ((?x588149 (ite $x585762 ?x380121 ?x436015)))
(let (($x613335 (and (distinct (_ bv0 32) (bvadd (bvmul (_ bv4294967295 32) (ite (bvule arg1 arg0) ?x436015 ?x380121)) ?x588149)) true)))
(let (($x19479 (and true true (or $x613335))))
(or $x19479)))))))))
(check-sat)
