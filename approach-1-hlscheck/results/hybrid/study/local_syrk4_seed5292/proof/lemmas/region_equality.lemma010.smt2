; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x524705 (bvmul arg0_0 arg0_3)))
(let ((?x432253 (bvmul (_ bv4294967295 32) ?x524705)))
(let ((?x527498 (bvmul arg0_0 arg0_12)))
(let ((?x432539 (bvadd ?x527498 ?x432253)))
(and (distinct ?x432539 (_ bv0 32)) true))))))
(check-sat)
