; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x502589 (bvmul arg0_13 arg1_13)))
(let ((?x477445 (bvmul (_ bv4294967295 32) ?x502589)))
(let ((?x515243 (bvmul arg0_13 arg1_7)))
(let ((?x316210 (bvadd ?x515243 ?x477445)))
(and (distinct ?x316210 (_ bv0 32)) true))))))
(check-sat)
