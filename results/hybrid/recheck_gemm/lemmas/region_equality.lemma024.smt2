; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x157 (bvmul arg0_6 arg1_14)))
(let ((?x5441 (bvmul (_ bv4294967295 32) ?x157)))
(let ((?x91 (bvmul arg0_6 arg1_11)))
(let ((?x12703 (bvadd ?x91 ?x5441)))
(and (distinct ?x12703 (_ bv0 32)) true))))))
(check-sat)
