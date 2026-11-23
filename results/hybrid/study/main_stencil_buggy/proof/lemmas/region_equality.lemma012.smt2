; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x1589 (bvmul arg0_6 arg2_2)))
(let ((?x710989 (bvmul (_ bv4294967295 32) ?x1589)))
(let ((?x209 (bvmul arg0_6 arg2_1)))
(let ((?x163 (bvadd ?x209 ?x710989)))
(and (distinct ?x163 (_ bv0 32)) true))))))
(check-sat)
