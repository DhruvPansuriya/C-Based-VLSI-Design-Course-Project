; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x391473 (bvmul arg0_6 arg1_10)))
(let ((?x492858 (bvmul (_ bv4294967295 32) ?x391473)))
(let ((?x489430 (bvmul arg0_6 arg1_11)))
(let ((?x476881 (bvadd ?x489430 ?x492858)))
(and (distinct ?x476881 (_ bv0 32)) true))))))
(check-sat)
