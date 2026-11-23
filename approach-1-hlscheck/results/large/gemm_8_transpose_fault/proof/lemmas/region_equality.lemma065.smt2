; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_25 () (_ BitVec 32))
(assert
 (let ((?x15167 (bvmul arg0_11 arg1_11)))
(let ((?x64824 (bvmul (_ bv4294967295 32) ?x15167)))
(let ((?x64083 (bvmul arg0_11 arg1_25)))
(let ((?x53335 (bvadd ?x64083 ?x64824)))
(and (distinct ?x53335 (_ bv0 32)) true))))))
(check-sat)
