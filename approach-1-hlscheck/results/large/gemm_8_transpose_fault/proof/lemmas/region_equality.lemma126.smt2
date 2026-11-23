; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg1_57 () (_ BitVec 32))
(assert
 (let ((?x75200 (bvmul arg0_23 arg1_15)))
(let ((?x9701 (bvmul (_ bv4294967295 32) ?x75200)))
(let ((?x45116 (bvmul arg0_23 arg1_57)))
(let ((?x68433 (bvadd ?x45116 ?x9701)))
(and (distinct ?x68433 (_ bv0 32)) true))))))
(check-sat)
