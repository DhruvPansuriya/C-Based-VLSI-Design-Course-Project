; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let (($x11659 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let ((?x2623 (bvmul (_ bv4294967295 32) arg0_5)))
(let ((?x710534 (bvmul (_ bv4294967295 32) arg0_2)))
(let ((?x715096 (bvadd ?x710534 ?x2623)))
(let (($x58 (and (distinct (_ bv0 32) ?x715096) true)))
(let (($x724746 (and true true (or $x58 $x11659 $x11659 $x11659 $x11659 $x11659 $x11659 $x11659 $x11659))))
(or $x724746))))))))
(check-sat)
