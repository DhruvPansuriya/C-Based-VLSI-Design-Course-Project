; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_60 () (_ BitVec 32))
(declare-fun arg0_20 () (_ BitVec 32))
(declare-fun arg1_39 () (_ BitVec 32))
(assert
 (let ((?x72921 (bvmul arg0_20 arg1_60)))
(let ((?x14131 (bvmul (_ bv4294967295 32) ?x72921)))
(let ((?x17685 (bvmul arg0_20 arg1_39)))
(let ((?x65605 (bvadd ?x17685 ?x14131)))
(and (distinct ?x65605 (_ bv0 32)) true))))))
(check-sat)
