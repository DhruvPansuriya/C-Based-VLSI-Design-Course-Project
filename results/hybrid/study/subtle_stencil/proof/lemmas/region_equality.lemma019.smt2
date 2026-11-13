; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x501260 (bvmul arg0_11 arg2_0)))
(let ((?x498205 (bvmul (_ bv4294967295 32) ?x501260)))
(let ((?x669718 (bvmul arg0_11 arg2_1)))
(let ((?x587520 (bvadd ?x669718 ?x498205)))
(and (distinct ?x587520 (_ bv0 32)) true))))))
(check-sat)
