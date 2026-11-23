; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x334643 (bvmul arg0_10 arg1_14)))
(let ((?x299106 (bvmul (_ bv4294967295 32) ?x334643)))
(let ((?x347867 (bvmul arg0_10 arg1_11)))
(let ((?x350184 (bvadd ?x347867 ?x299106)))
(and (distinct ?x350184 (_ bv0 32)) true))))))
(check-sat)
