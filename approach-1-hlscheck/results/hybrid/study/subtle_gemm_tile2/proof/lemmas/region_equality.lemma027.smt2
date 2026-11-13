; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x591323 (bvmul arg0_14 arg1_8)))
(let ((?x577355 (bvmul (_ bv4294967295 32) ?x591323)))
(let ((?x524921 (bvmul arg0_14 arg1_9)))
(let ((?x395211 (bvadd ?x524921 ?x577355)))
(and (distinct ?x395211 (_ bv0 32)) true))))))
(check-sat)
