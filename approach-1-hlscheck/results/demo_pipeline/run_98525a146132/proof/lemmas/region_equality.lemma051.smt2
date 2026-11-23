; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x161 (bvmul (_ bv4294967295 32) arg1_4)))
(let ((?x8069 (bvmul (_ bv4294967295 32) arg0_13)))
(let ((?x113 (bvmul arg0_13 arg1_4)))
(let ((?x11799 (bvadd ?x113 ?x8069 ?x161)))
(and (distinct ?x11799 (_ bv0 32)) true))))))
(check-sat)
