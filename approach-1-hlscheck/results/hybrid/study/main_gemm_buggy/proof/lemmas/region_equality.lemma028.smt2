; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x3009 (bvmul arg0_10 arg1_6)))
(let ((?x2616 (bvmul (_ bv4294967295 32) ?x3009)))
(let ((?x5044 (bvmul arg0_10 arg1_9)))
(let ((?x21249 (bvadd ?x5044 ?x2616)))
(and (distinct ?x21249 (_ bv0 32)) true))))))
(check-sat)
