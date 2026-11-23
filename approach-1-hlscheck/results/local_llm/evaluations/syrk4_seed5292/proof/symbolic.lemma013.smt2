; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x1323 (bvmul arg0_12 arg0_7)))
(let ((?x462 (bvmul (_ bv4294967295 32) ?x1323)))
(let ((?x40 (bvmul arg0_3 arg0_7)))
(let ((?x5343 (bvadd ?x40 ?x462)))
(and (distinct ?x5343 (_ bv0 32)) true))))))
(check-sat)
