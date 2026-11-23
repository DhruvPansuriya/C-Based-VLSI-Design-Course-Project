; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x138 (bvmul arg0_9 arg1_13)))
(let ((?x21967 (bvmul (_ bv4294967295 32) ?x138)))
(let ((?x166 (bvmul arg0_9 arg1_7)))
(let ((?x19324 (bvadd ?x166 ?x21967)))
(and (distinct ?x19324 (_ bv0 32)) true))))))
(check-sat)
