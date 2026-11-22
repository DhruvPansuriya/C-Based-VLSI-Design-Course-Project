; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_53 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_46 () (_ BitVec 32))
(assert
 (let ((?x75517 (bvmul arg0_5 arg1_53)))
(let ((?x59452 (bvmul (_ bv4294967295 32) ?x75517)))
(let ((?x45109 (bvmul arg0_5 arg1_46)))
(let ((?x74963 (bvadd ?x45109 ?x59452)))
(and (distinct ?x74963 (_ bv0 32)) true))))))
(check-sat)
