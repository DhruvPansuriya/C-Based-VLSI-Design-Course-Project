; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_62 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_55 () (_ BitVec 32))
(assert
 (let ((?x82 (bvmul arg0_14 arg1_62)))
(let ((?x68061 (bvmul (_ bv4294967295 32) ?x82)))
(let ((?x16013 (bvmul arg0_14 arg1_55)))
(let ((?x69882 (bvadd ?x16013 ?x68061)))
(and (distinct ?x69882 (_ bv0 32)) true))))))
(check-sat)
