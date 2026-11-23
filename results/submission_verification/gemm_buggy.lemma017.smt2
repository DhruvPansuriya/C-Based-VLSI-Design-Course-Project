; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x23 (bvmul arg0_6 arg1_6)))
(let ((?x15900 (bvmul (_ bv4294967295 32) ?x23)))
(let ((?x57 (bvmul arg0_6 arg1_9)))
(let ((?x19861 (bvadd ?x57 ?x15900)))
(and (distinct ?x19861 (_ bv0 32)) true))))))
(check-sat)
