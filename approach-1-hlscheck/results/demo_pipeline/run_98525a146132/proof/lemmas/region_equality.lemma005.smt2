; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x176 (bvmul (_ bv4294967295 32) arg1_1)))
(let ((?x155 (bvmul (_ bv4294967295 32) arg0_0)))
(let ((?x59 (bvmul arg0_0 arg1_1)))
(let ((?x2716 (bvadd ?x59 ?x155 ?x176)))
(and (distinct ?x2716 (_ bv0 32)) true))))))
(check-sat)
