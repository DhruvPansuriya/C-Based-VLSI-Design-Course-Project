; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x334534 (bvmul arg0_5 arg1_1)))
(let ((?x294187 (bvmul (_ bv4294967295 32) ?x334534)))
(let ((?x358910 (bvmul arg0_5 arg1_4)))
(let ((?x325952 (bvadd ?x358910 ?x294187)))
(and (distinct ?x325952 (_ bv0 32)) true))))))
(check-sat)
