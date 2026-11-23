; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x5020 (bvmul arg0_11 arg1_11)))
(let ((?x52 (bvmul (_ bv4294967295 32) ?x5020)))
(let ((?x191 (bvmul arg0_11 arg1_14)))
(let ((?x14110 (bvadd ?x191 ?x52)))
(and (distinct ?x14110 (_ bv0 32)) true))))))
(check-sat)
