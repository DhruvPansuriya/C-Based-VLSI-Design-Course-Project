; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_28 () (_ BitVec 32))
(declare-fun arg0_20 () (_ BitVec 32))
(declare-fun arg1_35 () (_ BitVec 32))
(assert
 (let ((?x72922 (bvmul arg0_20 arg1_28)))
(let ((?x71069 (bvmul (_ bv4294967295 32) ?x72922)))
(let ((?x63544 (bvmul arg0_20 arg1_35)))
(let ((?x72476 (bvadd ?x63544 ?x71069)))
(and (distinct ?x72476 (_ bv0 32)) true))))))
(check-sat)
