; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x18749 (bvmul arg0_18 arg2_6)))
(let ((?x714128 (bvmul (_ bv4294967295 32) ?x18749)))
(let ((?x53 (bvmul arg0_18 arg2_7)))
(let ((?x10204 (bvadd ?x53 ?x714128)))
(and (distinct ?x10204 (_ bv0 32)) true))))))
(check-sat)
