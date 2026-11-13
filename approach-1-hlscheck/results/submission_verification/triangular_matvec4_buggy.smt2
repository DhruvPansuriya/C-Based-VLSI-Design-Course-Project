; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let (($x365995 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let ((?x453924 (concat ((_ extract 31 1) (bvmul arg0_0 arg1_0)) (bvnot (bvmul ((_ extract 0 0) arg0_0) ((_ extract 0 0) arg1_0))))))
(let ((?x475908 (bvmul arg0_0 arg1_0)))
(let (($x10312 (and (distinct (_ bv0 32) (bvadd ?x475908 (bvmul (_ bv4294967295 32) ?x453924))) true)))
(let (($x433168 (or $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x365995 $x10312 $x365995 $x365995 $x365995)))
(let (($x361263 (and true true $x433168)))
(or $x361263))))))))
(check-sat)
