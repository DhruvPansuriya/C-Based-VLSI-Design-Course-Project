; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x159 (bvmul (_ bv4294967295 32) arg1_0)))
(let ((?x10459 (bvmul (_ bv4294967295 32) arg0_8)))
(let ((?x94 (bvmul arg0_8 arg1_0)))
(let ((?x1748 (bvadd ?x94 ?x10459 ?x159)))
(and (distinct ?x1748 (_ bv0 32)) true))))))
(check-sat)
