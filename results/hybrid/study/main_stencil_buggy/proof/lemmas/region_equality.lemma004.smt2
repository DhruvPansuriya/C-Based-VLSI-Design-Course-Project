; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x86 (bvmul arg0_12 arg2_8)))
(let ((?x720197 (bvmul (_ bv4294967295 32) ?x86)))
(let ((?x206 (bvmul arg0_12 arg2_7)))
(let ((?x714753 (bvadd ?x206 ?x720197)))
(and (distinct ?x714753 (_ bv0 32)) true))))))
(check-sat)
