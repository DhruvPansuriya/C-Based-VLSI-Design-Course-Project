; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x11832 (bvmul arg0_18 arg2_8)))
(let ((?x713534 (bvmul (_ bv4294967295 32) ?x11832)))
(let ((?x16577 (bvmul arg0_18 arg2_7)))
(let ((?x719401 (bvadd ?x16577 ?x713534)))
(and (distinct ?x719401 (_ bv0 32)) true))))))
(check-sat)
