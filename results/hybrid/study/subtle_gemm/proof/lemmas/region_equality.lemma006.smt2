; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x329525 (bvmul arg0_3 arg1_7)))
(let ((?x86439 (bvmul (_ bv4294967295 32) ?x329525)))
(let ((?x673164 (bvmul arg0_3 arg1_13)))
(let ((?x289414 (bvadd ?x673164 ?x86439)))
(and (distinct ?x289414 (_ bv0 32)) true))))))
(check-sat)
