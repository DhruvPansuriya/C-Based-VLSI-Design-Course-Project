; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_22 () (_ BitVec 32))
(declare-fun arg0_30 () (_ BitVec 32))
(declare-fun arg1_50 () (_ BitVec 32))
(assert
 (let ((?x63832 (bvmul arg0_30 arg1_22)))
(let ((?x70963 (bvmul (_ bv4294967295 32) ?x63832)))
(let ((?x2169 (bvmul arg0_30 arg1_50)))
(let ((?x53736 (bvadd ?x2169 ?x70963)))
(and (distinct ?x53736 (_ bv0 32)) true))))))
(check-sat)
