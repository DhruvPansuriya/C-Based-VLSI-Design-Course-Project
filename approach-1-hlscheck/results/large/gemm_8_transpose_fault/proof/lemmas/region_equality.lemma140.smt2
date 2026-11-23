; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_31 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg1_59 () (_ BitVec 32))
(assert
 (let ((?x75205 (bvmul arg0_23 arg1_31)))
(let ((?x72350 (bvmul (_ bv4294967295 32) ?x75205)))
(let ((?x9178 (bvmul arg0_23 arg1_59)))
(let ((?x71437 (bvadd ?x9178 ?x72350)))
(and (distinct ?x71437 (_ bv0 32)) true))))))
(check-sat)
