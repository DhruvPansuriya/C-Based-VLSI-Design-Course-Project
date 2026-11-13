; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_20 () (_ BitVec 32))
(declare-fun arg0_20 () (_ BitVec 32))
(declare-fun arg1_34 () (_ BitVec 32))
(assert
 (let ((?x75246 (bvmul arg0_20 arg1_20)))
(let ((?x57485 (bvmul (_ bv4294967295 32) ?x75246)))
(let ((?x31332 (bvmul arg0_20 arg1_34)))
(let ((?x62110 (bvadd ?x31332 ?x57485)))
(and (distinct ?x62110 (_ bv0 32)) true))))))
(check-sat)
