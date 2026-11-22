; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x683640 (bvmul arg0_6 arg1_8)))
(let ((?x603660 (bvmul (_ bv4294967295 32) ?x683640)))
(let ((?x395467 (bvmul arg0_6 arg1_9)))
(let ((?x477494 (bvadd ?x395467 ?x603660)))
(and (distinct ?x477494 (_ bv0 32)) true))))))
(check-sat)
