; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_20 () (_ BitVec 32))
(declare-fun arg1_32 () (_ BitVec 32))
(assert
 (let ((?x75216 (bvmul arg0_20 arg1_4)))
(let ((?x55742 (bvmul (_ bv4294967295 32) ?x75216)))
(let ((?x64092 (bvmul arg0_20 arg1_32)))
(let ((?x74108 (bvadd ?x64092 ?x55742)))
(and (distinct ?x74108 (_ bv0 32)) true))))))
(check-sat)
