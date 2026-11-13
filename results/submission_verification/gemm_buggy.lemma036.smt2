; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x97 (bvmul arg0_9 arg1_13)))
(let ((?x12047 (bvmul (_ bv4294967295 32) ?x97)))
(let ((?x236 (bvmul arg0_9 arg1_7)))
(let ((?x7988 (bvadd ?x236 ?x12047)))
(and (distinct ?x7988 (_ bv0 32)) true))))))
(check-sat)
