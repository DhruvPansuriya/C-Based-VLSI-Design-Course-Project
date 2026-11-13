; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x303392 (bvmul arg0_14 arg1_10)))
(let ((?x6348 (bvmul (_ bv4294967295 32) ?x303392)))
(let ((?x340728 (bvmul arg0_14 arg1_11)))
(let ((?x29431 (bvadd ?x340728 ?x6348)))
(and (distinct ?x29431 (_ bv0 32)) true))))))
(check-sat)
