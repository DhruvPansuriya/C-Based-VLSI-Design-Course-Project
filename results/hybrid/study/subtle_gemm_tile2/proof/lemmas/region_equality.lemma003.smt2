; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x41136 (bvmul arg0_2 arg1_8)))
(let ((?x586301 (bvmul (_ bv4294967295 32) ?x41136)))
(let ((?x391200 (bvmul arg0_2 arg1_9)))
(let ((?x588602 (bvadd ?x391200 ?x586301)))
(and (distinct ?x588602 (_ bv0 32)) true))))))
(check-sat)
