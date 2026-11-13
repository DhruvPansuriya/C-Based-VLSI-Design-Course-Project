; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_19 () (_ BitVec 32))
(declare-fun arg1_24 () (_ BitVec 32))
(assert
 (let ((?x72915 (bvmul arg0_19 arg1_3)))
(let ((?x64939 (bvmul (_ bv4294967295 32) ?x72915)))
(let ((?x33800 (bvmul arg0_19 arg1_24)))
(let ((?x62274 (bvadd ?x33800 ?x64939)))
(and (distinct ?x62274 (_ bv0 32)) true))))))
(check-sat)
