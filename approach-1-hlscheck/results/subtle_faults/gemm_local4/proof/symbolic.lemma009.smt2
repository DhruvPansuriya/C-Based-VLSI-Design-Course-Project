; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x19122 (bvmul arg0_10 arg1_10)))
(let ((?x16594 (bvmul (_ bv4294967295 32) ?x19122)))
(let ((?x380277 (bvmul arg0_10 arg1_11)))
(let ((?x7014 (bvadd ?x380277 ?x16594)))
(and (distinct ?x7014 (_ bv0 32)) true))))))
(check-sat)
