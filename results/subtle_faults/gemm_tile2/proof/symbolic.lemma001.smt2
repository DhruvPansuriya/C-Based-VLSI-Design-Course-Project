; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x493247 (bvmul arg0_0 arg1_0)))
(let ((?x415620 (bvmul (_ bv4294967295 32) ?x493247)))
(let ((?x354995 (bvmul arg0_0 arg1_1)))
(let ((?x16905 (bvadd ?x354995 ?x415620)))
(and (distinct ?x16905 (_ bv0 32)) true))))))
(check-sat)
