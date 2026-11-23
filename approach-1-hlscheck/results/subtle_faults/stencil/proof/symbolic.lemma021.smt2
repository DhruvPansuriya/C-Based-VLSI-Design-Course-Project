; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x21605 (bvmul arg0_21 arg2_6)))
(let ((?x717318 (bvmul (_ bv4294967295 32) ?x21605)))
(let ((?x144 (bvmul arg0_21 arg2_7)))
(let ((?x726967 (bvadd ?x144 ?x717318)))
(and (distinct ?x726967 (_ bv0 32)) true))))))
(check-sat)
