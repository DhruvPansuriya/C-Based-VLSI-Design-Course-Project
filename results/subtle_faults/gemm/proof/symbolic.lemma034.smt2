; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x171 (bvmul arg0_10 arg1_14)))
(let ((?x13321 (bvmul (_ bv4294967295 32) ?x171)))
(let ((?x88 (bvmul arg0_10 arg1_11)))
(let ((?x8880 (bvadd ?x88 ?x13321)))
(and (distinct ?x8880 (_ bv0 32)) true))))))
(check-sat)
