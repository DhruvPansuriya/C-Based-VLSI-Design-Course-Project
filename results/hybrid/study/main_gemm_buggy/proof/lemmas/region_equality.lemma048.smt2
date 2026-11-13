; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x3013 (bvmul arg0_14 arg1_14)))
(let ((?x10935 (bvmul (_ bv4294967295 32) ?x3013)))
(let ((?x91 (bvmul arg0_14 arg1_11)))
(let ((?x5557 (bvadd ?x91 ?x10935)))
(and (distinct ?x5557 (_ bv0 32)) true))))))
(check-sat)
