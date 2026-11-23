; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_30 () (_ BitVec 32))
(declare-fun arg1_48 () (_ BitVec 32))
(assert
 (let ((?x67012 (bvmul arg0_30 arg1_6)))
(let ((?x59585 (bvmul (_ bv4294967295 32) ?x67012)))
(let ((?x64072 (bvmul arg0_30 arg1_48)))
(let ((?x70963 (bvadd ?x64072 ?x59585)))
(and (distinct ?x70963 (_ bv0 32)) true))))))
(check-sat)
