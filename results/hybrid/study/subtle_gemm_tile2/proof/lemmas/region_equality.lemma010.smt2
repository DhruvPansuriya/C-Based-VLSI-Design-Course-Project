; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x13020 (bvmul arg0_5 arg1_4)))
(let ((?x448353 (bvmul (_ bv4294967295 32) ?x13020)))
(let ((?x9215 (bvmul arg0_5 arg1_5)))
(let ((?x403855 (bvadd ?x9215 ?x448353)))
(and (distinct ?x403855 (_ bv0 32)) true))))))
(check-sat)
