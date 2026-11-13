; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x508983 (bvmul arg0_13 arg2_0)))
(let ((?x592428 (bvmul (_ bv4294967295 32) ?x508983)))
(let ((?x334551 (bvmul arg0_13 arg2_1)))
(let ((?x288055 (bvadd ?x334551 ?x592428)))
(and (distinct ?x288055 (_ bv0 32)) true))))))
(check-sat)
