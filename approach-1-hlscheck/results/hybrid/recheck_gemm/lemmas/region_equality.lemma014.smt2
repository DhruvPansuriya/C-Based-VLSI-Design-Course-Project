; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x160 (bvmul arg0_6 arg1_2)))
(let ((?x12949 (bvmul (_ bv4294967295 32) ?x160)))
(let ((?x76 (bvmul arg0_6 arg1_8)))
(let ((?x6435 (bvadd ?x76 ?x12949)))
(and (distinct ?x6435 (_ bv0 32)) true))))))
(check-sat)
