; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x145 (bvmul arg0_10 arg1_2)))
(let ((?x13315 (bvmul (_ bv4294967295 32) ?x145)))
(let ((?x64 (bvmul arg0_10 arg1_8)))
(let ((?x10808 (bvadd ?x64 ?x13315)))
(and (distinct ?x10808 (_ bv0 32)) true))))))
(check-sat)
