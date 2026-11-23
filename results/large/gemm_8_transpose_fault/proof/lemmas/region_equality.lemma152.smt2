; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_44 () (_ BitVec 32))
(declare-fun arg0_20 () (_ BitVec 32))
(declare-fun arg1_37 () (_ BitVec 32))
(assert
 (let ((?x72916 (bvmul arg0_20 arg1_44)))
(let ((?x60817 (bvmul (_ bv4294967295 32) ?x72916)))
(let ((?x64024 (bvmul arg0_20 arg1_37)))
(let ((?x75111 (bvadd ?x64024 ?x60817)))
(and (distinct ?x75111 (_ bv0 32)) true))))))
(check-sat)
