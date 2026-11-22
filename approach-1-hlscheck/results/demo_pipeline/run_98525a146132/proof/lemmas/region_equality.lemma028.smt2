; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x180 (bvmul (_ bv4294967295 32) arg1_6)))
(let ((?x5297 (bvmul (_ bv4294967295 32) arg0_5)))
(let ((?x83 (bvmul arg0_5 arg1_6)))
(let ((?x205 (bvadd ?x83 ?x5297 ?x180)))
(and (distinct ?x205 (_ bv0 32)) true))))))
(check-sat)
