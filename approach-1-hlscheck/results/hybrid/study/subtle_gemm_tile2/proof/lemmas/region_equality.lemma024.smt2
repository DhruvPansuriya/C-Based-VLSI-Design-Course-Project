; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x415629 (bvmul arg0_9 arg1_6)))
(let ((?x585031 (bvmul (_ bv4294967295 32) ?x415629)))
(let ((?x407948 (bvmul arg0_9 arg1_7)))
(let ((?x352870 (bvadd ?x407948 ?x585031)))
(and (distinct ?x352870 (_ bv0 32)) true))))))
(check-sat)
