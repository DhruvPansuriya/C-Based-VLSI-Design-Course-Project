; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x12 (bvmul arg0_12 arg2_8)))
(let ((?x721129 (bvmul (_ bv4294967295 32) ?x12)))
(let ((?x18536 (bvmul arg0_12 arg2_7)))
(let ((?x714585 (bvadd ?x18536 ?x721129)))
(and (distinct ?x714585 (_ bv0 32)) true))))))
(check-sat)
