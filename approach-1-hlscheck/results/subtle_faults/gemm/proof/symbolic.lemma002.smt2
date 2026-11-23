; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x151 (bvmul arg0_2 arg1_2)))
(let ((?x224 (bvmul (_ bv4294967295 32) ?x151)))
(let ((?x127 (bvmul arg0_2 arg1_8)))
(let ((?x5551 (bvadd ?x127 ?x224)))
(and (distinct ?x5551 (_ bv0 32)) true))))))
(check-sat)
