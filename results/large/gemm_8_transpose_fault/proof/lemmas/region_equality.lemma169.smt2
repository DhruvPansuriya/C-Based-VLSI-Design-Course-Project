; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_25 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x63488 (bvmul arg0_25 arg1_1)))
(let ((?x67294 (bvmul (_ bv4294967295 32) ?x63488)))
(let ((?x45171 (bvmul arg0_25 arg1_8)))
(let ((?x57844 (bvadd ?x45171 ?x67294)))
(and (distinct ?x57844 (_ bv0 32)) true))))))
(check-sat)
