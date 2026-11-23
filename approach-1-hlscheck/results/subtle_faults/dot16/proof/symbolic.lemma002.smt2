; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x677852 (bvmul arg0_14 arg1_15)))
(let ((?x724630 (bvmul (_ bv4294967295 32) ?x677852)))
(let ((?x716310 (bvmul arg0_15 arg1_15)))
(let ((?x4117 (bvadd ?x716310 ?x724630)))
(and (distinct ?x4117 (_ bv0 32)) true))))))
(check-sat)
