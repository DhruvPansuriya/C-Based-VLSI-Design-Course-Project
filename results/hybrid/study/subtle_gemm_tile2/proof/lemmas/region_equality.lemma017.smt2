; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x9080 (bvmul arg0_10 arg1_8)))
(let ((?x389552 (bvmul (_ bv4294967295 32) ?x9080)))
(let ((?x392397 (bvmul arg0_10 arg1_9)))
(let ((?x517930 (bvadd ?x392397 ?x389552)))
(and (distinct ?x517930 (_ bv0 32)) true))))))
(check-sat)
