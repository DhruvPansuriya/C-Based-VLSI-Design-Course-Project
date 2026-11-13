; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x142 (bvmul arg0_13 arg1_9)))
(let ((?x11153 (bvmul (_ bv4294967295 32) ?x142)))
(let ((?x5024 (bvmul arg0_13 arg1_6)))
(let ((?x479 (bvadd ?x5024 ?x11153)))
(and (distinct ?x479 (_ bv0 32)) true))))))
(check-sat)
