; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x171 (bvmul (_ bv4294967295 32) arg1_10)))
(let ((?x2072 (bvmul (_ bv4294967295 32) arg0_14)))
(let ((?x127 (bvmul arg0_14 arg1_10)))
(let ((?x8229 (bvadd ?x127 ?x2072 ?x171)))
(and (distinct ?x8229 (_ bv0 32)) true))))))
(check-sat)
