; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x473876 (bvmul arg0_15 arg1_14)))
(let ((?x509594 (bvmul (_ bv4294967295 32) ?x473876)))
(let ((?x423586 (bvmul arg0_15 arg1_15)))
(let ((?x493444 (bvadd ?x423586 ?x509594)))
(and (distinct ?x493444 (_ bv0 32)) true))))))
(check-sat)
