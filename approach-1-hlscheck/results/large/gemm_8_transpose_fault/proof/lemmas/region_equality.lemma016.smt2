; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_17 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_10 () (_ BitVec 32))
(assert
 (let ((?x73087 (bvmul arg0_1 arg1_17)))
(let ((?x68222 (bvmul (_ bv4294967295 32) ?x73087)))
(let ((?x45167 (bvmul arg0_1 arg1_10)))
(let ((?x75939 (bvadd ?x45167 ?x68222)))
(and (distinct ?x75939 (_ bv0 32)) true))))))
(check-sat)
