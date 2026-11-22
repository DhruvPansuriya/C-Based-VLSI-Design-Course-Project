; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_31 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_59 () (_ BitVec 32))
(assert
 (let ((?x39424 (bvmul arg0_15 arg1_31)))
(let ((?x53899 (bvmul (_ bv4294967295 32) ?x39424)))
(let ((?x3014 (bvmul arg0_15 arg1_59)))
(let ((?x67495 (bvadd ?x3014 ?x53899)))
(and (distinct ?x67495 (_ bv0 32)) true))))))
(check-sat)
