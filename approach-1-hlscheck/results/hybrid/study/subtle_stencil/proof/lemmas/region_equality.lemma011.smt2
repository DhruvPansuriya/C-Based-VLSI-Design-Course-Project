; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x329392 (bvmul arg0_16 arg2_6)))
(let ((?x350281 (bvmul (_ bv4294967295 32) ?x329392)))
(let ((?x334554 (bvmul arg0_16 arg2_7)))
(let ((?x738307 (bvadd ?x334554 ?x350281)))
(and (distinct ?x738307 (_ bv0 32)) true))))))
(check-sat)
