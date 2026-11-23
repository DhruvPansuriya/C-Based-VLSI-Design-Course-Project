; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x139162 (bvmul arg0_14 arg1_8)))
(let ((?x486037 (bvmul (_ bv4294967295 32) ?x139162)))
(let ((?x418072 (bvmul arg0_14 arg1_9)))
(let ((?x476881 (bvadd ?x418072 ?x486037)))
(and (distinct ?x476881 (_ bv0 32)) true))))))
(check-sat)
