; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_19 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_26 () (_ BitVec 32))
(assert
 (let ((?x22323 (bvmul arg0_11 arg1_19)))
(let ((?x61211 (bvmul (_ bv4294967295 32) ?x22323)))
(let ((?x63769 (bvmul arg0_11 arg1_26)))
(let ((?x54666 (bvadd ?x63769 ?x61211)))
(and (distinct ?x54666 (_ bv0 32)) true))))))
(check-sat)
