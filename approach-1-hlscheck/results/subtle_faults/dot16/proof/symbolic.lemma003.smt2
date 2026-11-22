; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x727851 (bvmul arg0_2 arg1_3)))
(let ((?x713413 (bvmul (_ bv4294967295 32) ?x727851)))
(let ((?x646131 (bvmul arg0_3 arg1_3)))
(let ((?x22581 (bvadd ?x646131 ?x713413)))
(and (distinct ?x22581 (_ bv0 32)) true))))))
(check-sat)
