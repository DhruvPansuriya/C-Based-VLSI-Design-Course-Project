; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x111 (bvmul arg0_1 arg2_2)))
(let ((?x710399 (bvmul (_ bv4294967295 32) ?x111)))
(let ((?x21401 (bvmul arg0_1 arg2_1)))
(let ((?x344053 (bvadd ?x21401 ?x710399)))
(and (distinct ?x344053 (_ bv0 32)) true))))))
(check-sat)
