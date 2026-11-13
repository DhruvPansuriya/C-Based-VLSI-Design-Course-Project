; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x3473 (bvmul arg0_14 arg1_2)))
(let ((?x4861 (bvmul (_ bv4294967295 32) ?x3473)))
(let ((?x3499 (bvmul arg0_14 arg1_8)))
(let ((?x1566 (bvadd ?x3499 ?x4861)))
(and (distinct ?x1566 (_ bv0 32)) true))))))
(check-sat)
