; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x47 (bvmul arg0_10 arg1_14)))
(let ((?x2570 (bvmul (_ bv4294967295 32) ?x47)))
(let ((?x3477 (bvmul arg0_10 arg1_11)))
(let ((?x15871 (bvadd ?x3477 ?x2570)))
(and (distinct ?x15871 (_ bv0 32)) true))))))
(check-sat)
