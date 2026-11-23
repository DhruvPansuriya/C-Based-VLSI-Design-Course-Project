; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_62 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg1_55 () (_ BitVec 32))
(assert
 (let ((?x15543 (bvmul arg0_22 arg1_62)))
(let ((?x70410 (bvmul (_ bv4294967295 32) ?x15543)))
(let ((?x29689 (bvmul arg0_22 arg1_55)))
(let ((?x70844 (bvadd ?x29689 ?x70410)))
(and (distinct ?x70844 (_ bv0 32)) true))))))
(check-sat)
