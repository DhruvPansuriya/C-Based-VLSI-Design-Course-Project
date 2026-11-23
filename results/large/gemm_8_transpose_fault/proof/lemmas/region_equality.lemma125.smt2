; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg1_49 () (_ BitVec 32))
(assert
 (let ((?x72923 (bvmul arg0_22 arg1_14)))
(let ((?x64955 (bvmul (_ bv4294967295 32) ?x72923)))
(let ((?x64089 (bvmul arg0_22 arg1_49)))
(let ((?x71036 (bvadd ?x64089 ?x64955)))
(and (distinct ?x71036 (_ bv0 32)) true))))))
(check-sat)
