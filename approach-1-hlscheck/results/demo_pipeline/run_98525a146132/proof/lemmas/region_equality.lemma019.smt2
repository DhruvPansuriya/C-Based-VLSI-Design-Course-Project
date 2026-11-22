; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x161 (bvmul (_ bv4294967295 32) arg1_4)))
(let ((?x5297 (bvmul (_ bv4294967295 32) arg0_5)))
(let ((?x73 (bvmul arg0_5 arg1_4)))
(let ((?x200 (bvadd ?x73 ?x5297 ?x161)))
(and (distinct ?x200 (_ bv0 32)) true))))))
(check-sat)
