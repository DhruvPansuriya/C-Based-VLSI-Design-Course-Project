; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x330646 (bvmul arg0_4 arg1_8)))
(let ((?x322473 (bvmul (_ bv4294967295 32) ?x330646)))
(let ((?x332308 (bvmul arg0_4 arg1_2)))
(let ((?x310582 (bvadd ?x332308 ?x322473)))
(and (distinct ?x310582 (_ bv0 32)) true))))))
(check-sat)
