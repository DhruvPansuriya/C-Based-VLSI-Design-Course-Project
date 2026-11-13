; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x669 (bvmul arg0_10 arg1_11)))
(let ((?x16165 (bvmul (_ bv4294967295 32) ?x669)))
(let ((?x16492 (bvmul arg0_11 arg1_11)))
(let ((?x7178 (bvadd ?x16492 ?x16165)))
(and (distinct ?x7178 (_ bv0 32)) true))))))
(check-sat)
