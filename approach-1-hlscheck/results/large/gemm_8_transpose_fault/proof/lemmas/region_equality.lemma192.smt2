; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_26 () (_ BitVec 32))
(declare-fun arg0_26 () (_ BitVec 32))
(declare-fun arg1_19 () (_ BitVec 32))
(assert
 (let ((?x63708 (bvmul arg0_26 arg1_26)))
(let ((?x63895 (bvmul arg0_26 arg1_19)))
(let (($x56457 (= ?x63895 ?x63708)))
(not $x56457)))))
(check-sat)
