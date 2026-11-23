; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x164 (bvmul arg0_18 arg2_5)))
(let ((?x117 (bvmul (_ bv4294967295 32) ?x164)))
(let ((?x179 (bvmul arg0_18 arg2_4)))
(let ((?x12925 (bvadd ?x179 ?x117)))
(and (distinct ?x12925 (_ bv0 32)) true))))))
(check-sat)
