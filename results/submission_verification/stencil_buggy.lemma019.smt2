; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x128411 (bvmul arg0_11 arg2_2)))
(let ((?x730145 (bvmul (_ bv4294967295 32) ?x128411)))
(let ((?x14983 (bvmul arg0_11 arg2_1)))
(let ((?x720035 (bvadd ?x14983 ?x730145)))
(and (distinct ?x720035 (_ bv0 32)) true))))))
(check-sat)
