; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x510852 (bvadd (bvmul (_ bv4294967295 32) (bvmul arg0 arg1)) (bvmul arg0 arg0 arg1))))
(let (($x348732 (and (distinct (_ bv0 32) ?x510852) true)))
(let (($x741740 (and true true (or $x348732))))
(or $x741740)))))
(check-sat)
