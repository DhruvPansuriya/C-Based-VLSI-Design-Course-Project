; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x524802 (bvmul arg0_10 arg0_9)))
(let ((?x498205 (bvmul (_ bv4294967295 32) ?x524802)))
(let ((?x359249 (bvmul arg0_10 arg0_6)))
(let ((?x360375 (bvadd ?x359249 ?x498205)))
(and (distinct ?x360375 (_ bv0 32)) true))))))
(check-sat)
