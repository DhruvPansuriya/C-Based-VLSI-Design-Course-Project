; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x105 (bvmul arg0_6 arg1_14)))
(let ((?x13208 (bvmul (_ bv4294967295 32) ?x105)))
(let ((?x5043 (bvmul arg0_6 arg1_11)))
(let ((?x9198 (bvadd ?x5043 ?x13208)))
(and (distinct ?x9198 (_ bv0 32)) true))))))
(check-sat)
