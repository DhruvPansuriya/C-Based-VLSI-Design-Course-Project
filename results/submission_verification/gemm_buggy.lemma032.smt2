; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x2575 (bvmul arg0_8 arg1_8)))
(let ((?x14983 (bvmul (_ bv4294967295 32) ?x2575)))
(let ((?x186 (bvmul arg0_8 arg1_2)))
(let ((?x7507 (bvadd ?x186 ?x14983)))
(and (distinct ?x7507 (_ bv0 32)) true))))))
(check-sat)
