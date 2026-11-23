; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x464323 (bvmul arg0_12 arg1_12)))
(let ((?x468914 (bvmul (_ bv4294967295 32) ?x464323)))
(let ((?x293648 (bvmul arg0_12 arg1_3)))
(let ((?x327309 (bvadd ?x293648 ?x468914)))
(and (distinct ?x327309 (_ bv0 32)) true))))))
(check-sat)
