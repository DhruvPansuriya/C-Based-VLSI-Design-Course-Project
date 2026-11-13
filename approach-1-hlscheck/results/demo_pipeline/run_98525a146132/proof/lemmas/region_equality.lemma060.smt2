; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x180 (bvmul (_ bv4294967295 32) arg1_6)))
(let ((?x8069 (bvmul (_ bv4294967295 32) arg0_13)))
(let ((?x123 (bvmul arg0_13 arg1_6)))
(let ((?x218 (bvadd ?x123 ?x8069 ?x180)))
(and (distinct ?x218 (_ bv0 32)) true))))))
(check-sat)
