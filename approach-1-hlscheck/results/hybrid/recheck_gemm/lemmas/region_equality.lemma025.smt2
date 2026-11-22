; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x176 (bvmul arg0_10 arg1_2)))
(let ((?x12750 (bvmul (_ bv4294967295 32) ?x176)))
(let ((?x96 (bvmul arg0_10 arg1_8)))
(let ((?x19030 (bvadd ?x96 ?x12750)))
(and (distinct ?x19030 (_ bv0 32)) true))))))
(check-sat)
