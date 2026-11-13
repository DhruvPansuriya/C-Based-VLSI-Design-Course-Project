; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x168 (bvmul (_ bv4294967295 32) arg1_9)))
(let ((?x152 (bvmul (_ bv4294967295 32) arg0_10)))
(let ((?x102 (bvmul arg0_10 arg1_9)))
(let ((?x169 (bvadd ?x102 ?x152 ?x168)))
(and (distinct ?x169 (_ bv0 32)) true))))))
(check-sat)
