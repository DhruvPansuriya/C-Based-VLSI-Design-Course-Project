; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let (($x473847 (= ((_ extract 31 8) arg0) (_ bv0 24))))
(let ((?x425331 (ite $x473847 arg0 (_ bv255 32))))
(let ((?x116428 (ite (or (not $x473847) (= ((_ extract 7 0) arg0) (_ bv255 8))) (_ bv255 32) arg0)))
(let ((?x4877 (bvmul (_ bv4294967295 32) ?x116428)))
(let ((?x476415 (bvadd ?x4877 ?x425331)))
(let (($x474387 (and (distinct (_ bv0 32) ?x476415) true)))
(let (($x130573 (and true true (or $x474387))))
(or $x130573)))))))))
(check-sat)
