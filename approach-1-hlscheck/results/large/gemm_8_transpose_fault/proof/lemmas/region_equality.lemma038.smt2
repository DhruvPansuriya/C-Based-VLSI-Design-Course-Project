; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_42 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_21 () (_ BitVec 32))
(assert
 (let ((?x75315 (bvmul arg0_2 arg1_42)))
(let ((?x7403 (bvmul (_ bv4294967295 32) ?x75315)))
(let ((?x15130 (bvmul arg0_2 arg1_21)))
(let ((?x66483 (bvadd ?x15130 ?x7403)))
(and (distinct ?x66483 (_ bv0 32)) true))))))
(check-sat)
