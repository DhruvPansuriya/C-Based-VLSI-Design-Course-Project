; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x499240 (bvmul arg0_13 arg1_9)))
(let ((?x348357 (bvmul (_ bv4294967295 32) ?x499240)))
(let ((?x366697 (bvmul arg0_13 arg1_6)))
(let ((?x101795 (bvadd ?x366697 ?x348357)))
(and (distinct ?x101795 (_ bv0 32)) true))))))
(check-sat)
