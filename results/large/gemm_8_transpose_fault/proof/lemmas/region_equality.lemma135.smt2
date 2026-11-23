; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_25 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x72918 (bvmul arg0_17 arg1_25)))
(let ((?x67220 (bvmul (_ bv4294967295 32) ?x72918)))
(let ((?x2010 (bvmul arg0_17 arg1_11)))
(let ((?x55365 (bvadd ?x2010 ?x67220)))
(and (distinct ?x55365 (_ bv0 32)) true))))))
(check-sat)
