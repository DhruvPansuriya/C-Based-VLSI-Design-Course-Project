; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x9 (bvmul arg0_12 arg2_8)))
(let ((?x719316 (bvmul (_ bv4294967295 32) ?x9)))
(let ((?x15742 (bvmul arg0_12 arg2_7)))
(let ((?x713534 (bvadd ?x15742 ?x719316)))
(and (distinct ?x713534 (_ bv0 32)) true))))))
(check-sat)
