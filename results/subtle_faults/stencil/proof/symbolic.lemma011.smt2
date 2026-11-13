; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x10437 (bvmul arg0_16 arg2_6)))
(let ((?x87 (bvmul (_ bv4294967295 32) ?x10437)))
(let ((?x2630 (bvmul arg0_16 arg2_7)))
(let ((?x712029 (bvadd ?x2630 ?x87)))
(and (distinct ?x712029 (_ bv0 32)) true))))))
(check-sat)
