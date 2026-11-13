; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x35 (bvmul arg0_18 arg2_8)))
(let ((?x719037 (bvmul (_ bv4294967295 32) ?x35)))
(let ((?x219 (bvmul arg0_18 arg2_7)))
(let ((?x713127 (bvadd ?x219 ?x719037)))
(and (distinct ?x713127 (_ bv0 32)) true))))))
(check-sat)
