; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_20 () (_ BitVec 32))
(declare-fun arg0_28 () (_ BitVec 32))
(declare-fun arg1_34 () (_ BitVec 32))
(assert
 (let ((?x64111 (bvmul arg0_28 arg1_20)))
(let ((?x54342 (bvmul (_ bv4294967295 32) ?x64111)))
(let ((?x872 (bvmul arg0_28 arg1_34)))
(let ((?x53875 (bvadd ?x872 ?x54342)))
(and (distinct ?x53875 (_ bv0 32)) true))))))
(check-sat)
