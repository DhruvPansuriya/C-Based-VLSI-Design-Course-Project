; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x5246 (bvmul arg0_17 arg2_6)))
(let ((?x715425 (bvmul (_ bv4294967295 32) ?x5246)))
(let ((?x8702 (bvmul arg0_17 arg2_7)))
(let ((?x716854 (bvadd ?x8702 ?x715425)))
(and (distinct ?x716854 (_ bv0 32)) true))))))
(check-sat)
