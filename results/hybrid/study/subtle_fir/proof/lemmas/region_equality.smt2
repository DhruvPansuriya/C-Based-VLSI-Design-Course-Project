; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let (($x330645 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let (($x460585 (and (distinct (_ bv0 32) (bvadd (bvmul (_ bv3 32) arg0_7) (bvmul (_ bv4294967293 32) arg0_6))) true)))
(let (($x592521 (and true true (or $x460585 $x330645 $x330645 $x330645 $x330645 $x330645 $x330645 $x330645 $x330645))))
(or $x592521)))))
(check-sat)
