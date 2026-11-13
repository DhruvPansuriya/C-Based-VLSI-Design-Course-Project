; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x683640 (bvmul arg0_10 arg1_10)))
(let ((?x4059 (bvmul (_ bv4294967295 32) ?x683640)))
(let ((?x121811 (bvmul arg0_10 arg1_11)))
(let ((?x453014 (bvadd ?x121811 ?x4059)))
(and (distinct ?x453014 (_ bv0 32)) true))))))
(check-sat)
