; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x9382 (bvmul arg0_6 arg1_10)))
(let ((?x410096 (bvmul (_ bv4294967295 32) ?x9382)))
(let ((?x440081 (bvmul arg0_6 arg1_11)))
(let ((?x149657 (bvadd ?x440081 ?x410096)))
(and (distinct ?x149657 (_ bv0 32)) true))))))
(check-sat)
