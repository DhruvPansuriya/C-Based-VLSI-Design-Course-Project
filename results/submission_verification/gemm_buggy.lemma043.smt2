; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x201 (bvmul arg0_12 arg1_8)))
(let ((?x4423 (bvmul (_ bv4294967295 32) ?x201)))
(let ((?x152 (bvmul arg0_12 arg1_2)))
(let ((?x13104 (bvadd ?x152 ?x4423)))
(and (distinct ?x13104 (_ bv0 32)) true))))))
(check-sat)
