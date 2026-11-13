; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x340419 (bvmul arg0_2 arg1_2)))
(let ((?x518364 (bvmul (_ bv4294967295 32) ?x340419)))
(let ((?x303234 (bvmul arg0_2 arg1_8)))
(let ((?x294187 (bvadd ?x303234 ?x518364)))
(and (distinct ?x294187 (_ bv0 32)) true))))))
(check-sat)
