; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x88 (bvmul arg0_13 arg2_8)))
(let ((?x715610 (bvmul (_ bv4294967295 32) ?x88)))
(let ((?x9198 (bvmul arg0_13 arg2_7)))
(let ((?x729428 (bvadd ?x9198 ?x715610)))
(and (distinct ?x729428 (_ bv0 32)) true))))))
(check-sat)
