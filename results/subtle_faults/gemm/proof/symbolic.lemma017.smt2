; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x148 (bvmul arg0_6 arg1_6)))
(let ((?x6222 (bvmul (_ bv4294967295 32) ?x148)))
(let ((?x72 (bvmul arg0_6 arg1_9)))
(let ((?x20943 (bvadd ?x72 ?x6222)))
(and (distinct ?x20943 (_ bv0 32)) true))))))
(check-sat)
