; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_38 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_52 () (_ BitVec 32))
(assert
 (let ((?x75250 (bvmul arg0_6 arg1_38)))
(let ((?x63442 (bvmul (_ bv4294967295 32) ?x75250)))
(let ((?x39414 (bvmul arg0_6 arg1_52)))
(let ((?x66537 (bvadd ?x39414 ?x63442)))
(and (distinct ?x66537 (_ bv0 32)) true))))))
(check-sat)
