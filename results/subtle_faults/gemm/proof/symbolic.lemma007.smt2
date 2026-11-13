; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x22 (bvmul arg0_0 arg1_8)))
(let ((?x330 (bvmul (_ bv4294967295 32) ?x22)))
(let ((?x120 (bvmul arg0_0 arg1_2)))
(let ((?x316 (bvadd ?x120 ?x330)))
(and (distinct ?x316 (_ bv0 32)) true))))))
(check-sat)
