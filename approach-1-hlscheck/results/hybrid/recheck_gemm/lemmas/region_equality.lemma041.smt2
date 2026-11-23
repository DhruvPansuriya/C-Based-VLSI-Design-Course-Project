; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x185 (bvmul arg0_14 arg1_6)))
(let ((?x11508 (bvmul (_ bv4294967295 32) ?x185)))
(let ((?x121 (bvmul arg0_14 arg1_9)))
(let ((?x4541 (bvadd ?x121 ?x11508)))
(and (distinct ?x4541 (_ bv0 32)) true))))))
(check-sat)
