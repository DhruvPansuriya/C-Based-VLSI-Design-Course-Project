; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_22 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg1_50 () (_ BitVec 32))
(assert
 (let ((?x72931 (bvmul arg0_22 arg1_22)))
(let ((?x68950 (bvmul (_ bv4294967295 32) ?x72931)))
(let ((?x73265 (bvmul arg0_22 arg1_50)))
(let ((?x69191 (bvadd ?x73265 ?x68950)))
(and (distinct ?x69191 (_ bv0 32)) true))))))
(check-sat)
