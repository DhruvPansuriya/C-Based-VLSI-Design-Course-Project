; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let (($x522064 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let ((?x469647 (concat ((_ extract 31 1) arg0_0) (bvnot ((_ extract 0 0) arg0_0)))))
(let ((?x503119 (bvmul (_ bv4294967295 32) ?x469647)))
(let ((?x499124 (bvadd arg0_0 ?x503119)))
(let (($x460513 (and (distinct (_ bv0 32) ?x499124) true)))
(let (($x443315 (or $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x460513 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064 $x522064)))
(let (($x460243 (and true true $x443315)))
(or $x460243)))))))))
(check-sat)
