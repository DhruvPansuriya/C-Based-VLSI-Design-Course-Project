; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x368920 (bvadd (bvmul (_ bv4294967295 32) (bvmul arg0 arg1)) (bvmul arg0 arg0 arg1))))
(let (($x381485 (and (distinct (_ bv0 32) ?x368920) true)))
(let (($x369305 (and true true (or $x381485))))
(or $x369305)))))
(check-sat)
