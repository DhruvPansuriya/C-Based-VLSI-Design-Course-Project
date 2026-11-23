; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x138 (bvmul arg0_2 arg1_6)))
(let ((?x12121 (bvmul (_ bv4294967295 32) ?x138)))
(let ((?x61 (bvmul arg0_2 arg1_9)))
(let ((?x7450 (bvadd ?x61 ?x12121)))
(and (distinct ?x7450 (_ bv0 32)) true))))))
(check-sat)
