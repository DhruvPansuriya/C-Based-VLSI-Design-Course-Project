; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x336346 (bvmul arg0_12 arg1_2)))
(let ((?x524921 (bvmul (_ bv4294967295 32) ?x336346)))
(let ((?x8516 (bvmul arg0_12 arg1_3)))
(let ((?x379848 (bvadd ?x8516 ?x524921)))
(and (distinct ?x379848 (_ bv0 32)) true))))))
(check-sat)
