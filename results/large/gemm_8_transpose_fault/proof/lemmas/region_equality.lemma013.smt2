; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_49 () (_ BitVec 32))
(assert
 (let ((?x30662 (bvmul arg0_6 arg1_14)))
(let ((?x65418 (bvmul (_ bv4294967295 32) ?x30662)))
(let ((?x6241 (bvmul arg0_6 arg1_49)))
(let ((?x64287 (bvadd ?x6241 ?x65418)))
(and (distinct ?x64287 (_ bv0 32)) true))))))
(check-sat)
