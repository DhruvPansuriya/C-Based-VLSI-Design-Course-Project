; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_62 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_55 () (_ BitVec 32))
(assert
 (let ((?x2895 (bvmul arg0_6 arg1_62)))
(let ((?x53389 (bvmul (_ bv4294967295 32) ?x2895)))
(let ((?x75357 (bvmul arg0_6 arg1_55)))
(let ((?x72770 (bvadd ?x75357 ?x53389)))
(and (distinct ?x72770 (_ bv0 32)) true))))))
(check-sat)
