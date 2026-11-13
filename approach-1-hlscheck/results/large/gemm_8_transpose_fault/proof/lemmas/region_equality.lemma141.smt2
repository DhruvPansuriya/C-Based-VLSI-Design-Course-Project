; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_32 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x75232 (bvmul arg0_16 arg1_32)))
(let ((?x19937 (bvmul (_ bv4294967295 32) ?x75232)))
(let ((?x4896 (bvmul arg0_16 arg1_4)))
(let ((?x67052 (bvadd ?x4896 ?x19937)))
(and (distinct ?x67052 (_ bv0 32)) true))))))
(check-sat)
