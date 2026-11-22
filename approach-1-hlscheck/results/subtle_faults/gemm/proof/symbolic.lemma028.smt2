; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x168 (bvmul arg0_10 arg1_6)))
(let ((?x21602 (bvmul (_ bv4294967295 32) ?x168)))
(let ((?x26 (bvmul arg0_10 arg1_9)))
(let ((?x334 (bvadd ?x26 ?x21602)))
(and (distinct ?x334 (_ bv0 32)) true))))))
(check-sat)
