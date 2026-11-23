; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x161 (bvmul (_ bv4294967295 32) arg1_4)))
(let ((?x156 (bvmul (_ bv4294967295 32) arg0_1)))
(let ((?x55 (bvmul arg0_1 arg1_4)))
(let ((?x226 (bvadd ?x55 ?x156 ?x161)))
(and (distinct ?x226 (_ bv0 32)) true))))))
(check-sat)
