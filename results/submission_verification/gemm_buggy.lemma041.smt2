; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x134 (bvmul arg0_14 arg1_6)))
(let ((?x5440 (bvmul (_ bv4294967295 32) ?x134)))
(let ((?x41 (bvmul arg0_14 arg1_9)))
(let ((?x231 (bvadd ?x41 ?x5440)))
(and (distinct ?x231 (_ bv0 32)) true))))))
(check-sat)
