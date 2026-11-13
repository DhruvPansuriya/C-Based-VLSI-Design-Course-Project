; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_39 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_60 () (_ BitVec 32))
(assert
 (let ((?x25349 (bvmul arg0_15 arg1_39)))
(let ((?x65025 (bvmul (_ bv4294967295 32) ?x25349)))
(let ((?x63766 (bvmul arg0_15 arg1_60)))
(let ((?x55121 (bvadd ?x63766 ?x65025)))
(and (distinct ?x55121 (_ bv0 32)) true))))))
(check-sat)
