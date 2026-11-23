; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_22 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_50 () (_ BitVec 32))
(assert
 (let ((?x12472 (bvmul arg0_14 arg1_22)))
(let ((?x74264 (bvmul (_ bv4294967295 32) ?x12472)))
(let ((?x33669 (bvmul arg0_14 arg1_50)))
(let ((?x71015 (bvadd ?x33669 ?x74264)))
(and (distinct ?x71015 (_ bv0 32)) true))))))
(check-sat)
