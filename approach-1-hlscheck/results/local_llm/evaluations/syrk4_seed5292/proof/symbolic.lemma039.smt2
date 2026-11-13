; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x4113 (bvmul arg0_14 arg0_8)))
(let ((?x26313 (bvmul (_ bv4294967295 32) ?x4113)))
(let ((?x4052 (bvmul arg0_14 arg0_2)))
(let ((?x28296 (bvadd ?x4052 ?x26313)))
(and (distinct ?x28296 (_ bv0 32)) true))))))
(check-sat)
