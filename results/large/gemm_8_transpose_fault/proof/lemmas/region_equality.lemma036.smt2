; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_40 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x73287 (bvmul arg0_0 arg1_40)))
(let ((?x67302 (bvmul (_ bv4294967295 32) ?x73287)))
(let ((?x63630 (bvmul arg0_0 arg1_5)))
(let ((?x73967 (bvadd ?x63630 ?x67302)))
(and (distinct ?x73967 (_ bv0 32)) true))))))
(check-sat)
