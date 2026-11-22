; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x34 (bvmul arg0_0 arg1_8)))
(let ((?x1570 (bvmul (_ bv4294967295 32) ?x34)))
(let ((?x74 (bvmul arg0_0 arg1_2)))
(let ((?x141 (bvadd ?x74 ?x1570)))
(and (distinct ?x141 (_ bv0 32)) true))))))
(check-sat)
