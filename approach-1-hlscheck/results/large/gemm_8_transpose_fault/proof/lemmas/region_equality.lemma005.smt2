; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_5 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_40 () (_ BitVec 32))
(assert
 (let ((?x75308 (bvmul arg0_5 arg1_5)))
(let ((?x64492 (bvmul (_ bv4294967295 32) ?x75308)))
(let ((?x73123 (bvmul arg0_5 arg1_40)))
(let ((?x68330 (bvadd ?x73123 ?x64492)))
(and (distinct ?x68330 (_ bv0 32)) true))))))
(check-sat)
