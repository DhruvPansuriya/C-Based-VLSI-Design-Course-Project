; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x334552 (bvmul arg0_6 arg1_6)))
(let ((?x466567 (bvmul (_ bv4294967295 32) ?x334552)))
(let ((?x340473 (bvmul arg0_6 arg1_9)))
(let ((?x342051 (bvadd ?x340473 ?x466567)))
(and (distinct ?x342051 (_ bv0 32)) true))))))
(check-sat)
