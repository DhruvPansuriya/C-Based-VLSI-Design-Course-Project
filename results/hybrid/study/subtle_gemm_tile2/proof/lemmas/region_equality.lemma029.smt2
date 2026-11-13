; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x507053 (bvmul arg0_12 arg1_2)))
(let ((?x452046 (bvmul (_ bv4294967295 32) ?x507053)))
(let ((?x411047 (bvmul arg0_12 arg1_3)))
(let ((?x215215 (bvadd ?x411047 ?x452046)))
(and (distinct ?x215215 (_ bv0 32)) true))))))
(check-sat)
