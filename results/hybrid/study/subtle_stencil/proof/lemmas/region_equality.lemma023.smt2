; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x330090 (bvmul arg0_17 arg2_3)))
(let ((?x467615 (bvmul (_ bv4294967295 32) ?x330090)))
(let ((?x314232 (bvmul arg0_17 arg2_4)))
(let ((?x554788 (bvadd ?x314232 ?x467615)))
(and (distinct ?x554788 (_ bv0 32)) true))))))
(check-sat)
