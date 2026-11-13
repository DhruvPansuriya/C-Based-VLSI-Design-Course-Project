; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x329392 (bvmul arg0_5 arg1_13)))
(let ((?x312210 (bvmul (_ bv4294967295 32) ?x329392)))
(let ((?x453013 (bvmul arg0_5 arg1_7)))
(let ((?x326752 (bvadd ?x453013 ?x312210)))
(and (distinct ?x326752 (_ bv0 32)) true))))))
(check-sat)
