; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x143354 (bvmul arg0_12 arg1_8)))
(let ((?x34973 (bvmul (_ bv4294967295 32) ?x143354)))
(let ((?x515476 (bvmul arg0_12 arg1_2)))
(let ((?x347154 (bvadd ?x515476 ?x34973)))
(and (distinct ?x347154 (_ bv0 32)) true))))))
(check-sat)
