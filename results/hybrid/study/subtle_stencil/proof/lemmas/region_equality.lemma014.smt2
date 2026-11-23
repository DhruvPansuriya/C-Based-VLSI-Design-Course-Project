; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x11610 (bvmul arg0_17 arg2_6)))
(let ((?x468121 (bvmul (_ bv4294967295 32) ?x11610)))
(let ((?x312210 (bvmul arg0_17 arg2_7)))
(let ((?x722224 (bvadd ?x312210 ?x468121)))
(and (distinct ?x722224 (_ bv0 32)) true))))))
(check-sat)
