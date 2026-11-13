; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x86 (bvmul arg0_7 arg1_11)))
(let ((?x20 (bvmul (_ bv4294967295 32) ?x86)))
(let ((?x42 (bvmul arg0_7 arg1_14)))
(let ((?x41 (bvadd ?x42 ?x20)))
(and (distinct ?x41 (_ bv0 32)) true))))))
(check-sat)
