; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_34 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_20 () (_ BitVec 32))
(assert
 (let ((?x73080 (bvmul arg0_2 arg1_34)))
(let ((?x74999 (bvmul (_ bv4294967295 32) ?x73080)))
(let ((?x73266 (bvmul arg0_2 arg1_20)))
(let ((?x55237 (bvadd ?x73266 ?x74999)))
(and (distinct ?x55237 (_ bv0 32)) true))))))
(check-sat)
