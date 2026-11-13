; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x90 (bvmul arg0_22 arg2_8)))
(let ((?x717775 (bvmul (_ bv4294967295 32) ?x90)))
(let ((?x45 (bvmul arg0_22 arg2_7)))
(let ((?x713095 (bvadd ?x45 ?x717775)))
(and (distinct ?x713095 (_ bv0 32)) true))))))
(check-sat)
