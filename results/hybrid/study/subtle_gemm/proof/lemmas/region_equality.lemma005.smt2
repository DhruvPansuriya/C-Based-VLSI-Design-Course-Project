; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x340589 (bvmul arg0_2 arg1_6)))
(let ((?x322411 (bvmul (_ bv4294967295 32) ?x340589)))
(let ((?x303981 (bvmul arg0_2 arg1_9)))
(let ((?x303616 (bvadd ?x303981 ?x322411)))
(and (distinct ?x303616 (_ bv0 32)) true))))))
(check-sat)
