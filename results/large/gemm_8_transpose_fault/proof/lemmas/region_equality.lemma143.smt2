; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_34 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg1_20 () (_ BitVec 32))
(assert
 (let ((?x75212 (bvmul arg0_18 arg1_34)))
(let ((?x64225 (bvmul (_ bv4294967295 32) ?x75212)))
(let ((?x45172 (bvmul arg0_18 arg1_20)))
(let ((?x60359 (bvadd ?x45172 ?x64225)))
(and (distinct ?x60359 (_ bv0 32)) true))))))
(check-sat)
