; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x61950 (bvmul arg0_14 arg1_10)))
(let ((?x489122 (bvmul (_ bv4294967295 32) ?x61950)))
(let ((?x480954 (bvmul arg0_14 arg1_11)))
(let ((?x484107 (bvadd ?x480954 ?x489122)))
(and (distinct ?x484107 (_ bv0 32)) true))))))
(check-sat)
