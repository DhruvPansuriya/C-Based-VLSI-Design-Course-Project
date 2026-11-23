; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_24 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x26480 (bvmul arg0_16 arg1_24)))
(let ((?x63476 (bvmul (_ bv4294967295 32) ?x26480)))
(let ((?x63543 (bvmul arg0_16 arg1_3)))
(let ((?x14131 (bvadd ?x63543 ?x63476)))
(and (distinct ?x14131 (_ bv0 32)) true))))))
(check-sat)
