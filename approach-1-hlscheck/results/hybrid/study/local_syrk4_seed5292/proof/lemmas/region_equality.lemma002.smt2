; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x377189 (bvmul arg0_12 arg0_3)))
(let ((?x12110 (bvmul (_ bv4294967295 32) ?x377189)))
(let ((?x515243 (bvmul arg0_3 arg0_3)))
(let ((?x511244 (bvadd ?x515243 ?x12110)))
(and (distinct ?x511244 (_ bv0 32)) true))))))
(check-sat)
