; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_38 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg1_52 () (_ BitVec 32))
(assert
 (let ((?x75208 (bvmul arg0_22 arg1_38)))
(let ((?x66338 (bvmul (_ bv4294967295 32) ?x75208)))
(let ((?x6306 (bvmul arg0_22 arg1_52)))
(let ((?x57491 (bvadd ?x6306 ?x66338)))
(and (distinct ?x57491 (_ bv0 32)) true))))))
(check-sat)
