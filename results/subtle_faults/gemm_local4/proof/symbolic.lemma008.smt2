; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x4652 (bvmul arg0_7 arg1_14)))
(let ((?x407507 (bvmul (_ bv4294967295 32) ?x4652)))
(let ((?x84119 (bvmul arg0_7 arg1_15)))
(let ((?x23835 (bvadd ?x84119 ?x407507)))
(and (distinct ?x23835 (_ bv0 32)) true))))))
(check-sat)
