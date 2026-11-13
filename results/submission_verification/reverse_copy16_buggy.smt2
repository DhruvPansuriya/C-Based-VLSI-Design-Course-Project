; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let (($x75704 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let ((?x22244 (concat ((_ extract 31 1) arg0_15) (bvnot ((_ extract 0 0) arg0_15)))))
(let ((?x469927 (bvmul (_ bv4294967295 32) ?x22244)))
(let (($x527214 (and (distinct (_ bv0 32) (bvadd arg0_15 ?x469927)) true)))
(let (($x487664 (or $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x527214 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704 $x75704)))
(let (($x472232 (and true true $x487664)))
(or $x472232))))))))
(check-sat)
