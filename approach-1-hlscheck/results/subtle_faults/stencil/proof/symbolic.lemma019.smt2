; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x15129 (bvmul arg0_11 arg2_0)))
(let ((?x723117 (bvmul (_ bv4294967295 32) ?x15129)))
(let ((?x996 (bvmul arg0_11 arg2_1)))
(let ((?x714254 (bvadd ?x996 ?x723117)))
(and (distinct ?x714254 (_ bv0 32)) true))))))
(check-sat)
