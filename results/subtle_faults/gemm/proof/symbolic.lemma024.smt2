; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x155 (bvmul arg0_6 arg1_14)))
(let ((?x7650 (bvmul (_ bv4294967295 32) ?x155)))
(let ((?x29 (bvmul arg0_6 arg1_11)))
(let ((?x2704 (bvadd ?x29 ?x7650)))
(and (distinct ?x2704 (_ bv0 32)) true))))))
(check-sat)
