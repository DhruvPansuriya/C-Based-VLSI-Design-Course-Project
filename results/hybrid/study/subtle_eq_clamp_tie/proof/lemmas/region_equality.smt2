; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let (($x148905 (= ((_ extract 31 8) arg0) (_ bv0 24))))
(let ((?x738853 (ite $x148905 arg0 (_ bv255 32))))
(let ((?x143733 (ite (or (not $x148905) (= ((_ extract 7 0) arg0) (_ bv255 8))) (_ bv255 32) arg0)))
(let ((?x19516 (bvmul (_ bv4294967295 32) ?x143733)))
(let ((?x608298 (bvadd ?x19516 ?x738853)))
(let (($x394842 (and (distinct (_ bv0 32) ?x608298) true)))
(let (($x740633 (and true true (or $x394842))))
(or $x740633)))))))))
(check-sat)
