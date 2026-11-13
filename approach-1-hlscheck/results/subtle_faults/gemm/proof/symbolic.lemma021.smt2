; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x161 (bvmul arg0_7 arg1_11)))
(let ((?x229 (bvmul (_ bv4294967295 32) ?x161)))
(let ((?x207 (bvmul arg0_7 arg1_14)))
(let ((?x6057 (bvadd ?x207 ?x229)))
(and (distinct ?x6057 (_ bv0 32)) true))))))
(check-sat)
