; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x208 (bvmul arg0_13 arg1_13)))
(let ((?x13801 (bvmul (_ bv4294967295 32) ?x208)))
(let ((?x27 (bvmul arg0_13 arg1_7)))
(let ((?x6611 (bvadd ?x27 ?x13801)))
(and (distinct ?x6611 (_ bv0 32)) true))))))
(check-sat)
