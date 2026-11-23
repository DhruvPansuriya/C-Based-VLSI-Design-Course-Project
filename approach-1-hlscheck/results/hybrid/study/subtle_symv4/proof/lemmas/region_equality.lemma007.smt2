; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x380121 (bvmul arg0_5 arg1_1)))
(let ((?x379747 (bvmul (_ bv4294967295 32) ?x380121)))
(and (distinct ?x379747 (_ bv0 32)) true))))
(check-sat)
