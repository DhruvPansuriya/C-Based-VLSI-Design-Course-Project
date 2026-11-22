; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x74 (bvmul arg0_17 arg2_5)))
(let ((?x175 (bvmul (_ bv4294967295 32) ?x74)))
(let ((?x85 (bvmul arg0_17 arg2_4)))
(let ((?x725973 (bvadd ?x85 ?x175)))
(and (distinct ?x725973 (_ bv0 32)) true))))))
(check-sat)
