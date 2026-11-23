; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_24 () (_ BitVec 32))
(assert
 (let ((?x75314 (bvmul arg0_3 arg1_3)))
(let ((?x64392 (bvmul (_ bv4294967295 32) ?x75314)))
(let ((?x10631 (bvmul arg0_3 arg1_24)))
(let ((?x59392 (bvadd ?x10631 ?x64392)))
(and (distinct ?x59392 (_ bv0 32)) true))))))
(check-sat)
