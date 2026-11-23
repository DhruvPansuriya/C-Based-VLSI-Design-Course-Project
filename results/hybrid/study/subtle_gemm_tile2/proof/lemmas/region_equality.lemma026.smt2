; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x380559 (bvmul arg0_13 arg1_4)))
(let ((?x586552 (bvmul (_ bv4294967295 32) ?x380559)))
(let ((?x473710 (bvmul arg0_13 arg1_5)))
(let ((?x577662 (bvadd ?x473710 ?x586552)))
(and (distinct ?x577662 (_ bv0 32)) true))))))
(check-sat)
