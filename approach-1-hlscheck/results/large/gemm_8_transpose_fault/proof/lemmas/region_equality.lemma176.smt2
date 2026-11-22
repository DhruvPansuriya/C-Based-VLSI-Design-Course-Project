; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_24 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x72934 (bvmul arg0_24 arg1_8)))
(let ((?x74714 (bvmul (_ bv4294967295 32) ?x72934)))
(let ((?x19891 (bvmul arg0_24 arg1_1)))
(let ((?x67030 (bvadd ?x19891 ?x74714)))
(and (distinct ?x67030 (_ bv0 32)) true))))))
(check-sat)
