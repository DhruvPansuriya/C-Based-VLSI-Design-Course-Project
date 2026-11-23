; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_17 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg1_10 () (_ BitVec 32))
(assert
 (let ((?x75242 (bvmul arg0_17 arg1_17)))
(let ((?x74108 (bvmul (_ bv4294967295 32) ?x75242)))
(let ((?x63387 (bvmul arg0_17 arg1_10)))
(let ((?x56243 (bvadd ?x63387 ?x74108)))
(and (distinct ?x56243 (_ bv0 32)) true))))))
(check-sat)
