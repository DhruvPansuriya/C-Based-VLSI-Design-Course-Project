; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x347867 (bvmul arg0_14 arg1_15)))
(let ((?x177617 (bvmul (_ bv4294967295 32) ?x347867)))
(let ((?x435555 (bvmul arg0_15 arg1_15)))
(let ((?x563413 (bvadd ?x435555 ?x177617)))
(and (distinct ?x563413 (_ bv0 32)) true))))))
(check-sat)
