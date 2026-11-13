; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_26 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg1_19 () (_ BitVec 32))
(assert
 (let ((?x75218 (bvmul arg0_18 arg1_26)))
(let ((?x64965 (bvmul (_ bv4294967295 32) ?x75218)))
(let ((?x3971 (bvmul arg0_18 arg1_19)))
(let ((?x58552 (bvadd ?x3971 ?x64965)))
(and (distinct ?x58552 (_ bv0 32)) true))))))
(check-sat)
