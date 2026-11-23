; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x13049 (bvmul arg0_17 arg2_8)))
(let ((?x7988 (bvmul (_ bv4294967295 32) ?x13049)))
(let ((?x204 (bvmul arg0_17 arg2_7)))
(let ((?x726006 (bvadd ?x204 ?x7988)))
(and (distinct ?x726006 (_ bv0 32)) true))))))
(check-sat)
