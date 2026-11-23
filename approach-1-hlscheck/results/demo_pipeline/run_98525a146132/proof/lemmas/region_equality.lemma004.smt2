; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x162 (bvmul (_ bv4294967295 32) arg1_8)))
(let ((?x157 (bvmul (_ bv4294967295 32) arg0_2)))
(let ((?x57 (bvmul arg0_2 arg1_8)))
(let ((?x258 (bvadd ?x57 ?x157 ?x162)))
(and (distinct ?x258 (_ bv0 32)) true))))))
(check-sat)
