; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x1094 (bvmul arg0_14 arg0_3)))
(let ((?x1689 (bvmul (_ bv4294967295 32) ?x1094)))
(let ((?x807 (bvmul arg0_11 arg0_3)))
(let ((?x6639 (bvadd ?x807 ?x1689)))
(and (distinct ?x6639 (_ bv0 32)) true))))))
(check-sat)
