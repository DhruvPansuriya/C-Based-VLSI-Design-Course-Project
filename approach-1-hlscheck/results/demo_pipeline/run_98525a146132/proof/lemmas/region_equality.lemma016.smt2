; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x188 (bvmul (_ bv4294967295 32) arg1_7)))
(let ((?x156 (bvmul (_ bv4294967295 32) arg0_1)))
(let ((?x68 (bvmul arg0_1 arg1_7)))
(let ((?x252 (bvadd ?x68 ?x156 ?x188)))
(and (distinct ?x252 (_ bv0 32)) true))))))
(check-sat)
