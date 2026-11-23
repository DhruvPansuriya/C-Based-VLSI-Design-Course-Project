; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x159 (bvmul arg0_8 arg1_8)))
(let ((?x2199 (bvmul (_ bv4294967295 32) ?x159)))
(let ((?x33 (bvmul arg0_8 arg1_2)))
(let ((?x12809 (bvadd ?x33 ?x2199)))
(and (distinct ?x12809 (_ bv0 32)) true))))))
(check-sat)
