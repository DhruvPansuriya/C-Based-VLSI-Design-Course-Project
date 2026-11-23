; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x524845 (bvmul arg0_14 arg0_9)))
(let ((?x457120 (bvmul (_ bv4294967295 32) ?x524845)))
(let ((?x528665 (bvmul arg0_14 arg0_6)))
(let ((?x16541 (bvadd ?x528665 ?x457120)))
(and (distinct ?x16541 (_ bv0 32)) true))))))
(check-sat)
