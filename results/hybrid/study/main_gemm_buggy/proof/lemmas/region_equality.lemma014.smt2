; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x118 (bvmul arg0_6 arg1_2)))
(let ((?x15171 (bvmul (_ bv4294967295 32) ?x118)))
(let ((?x73 (bvmul arg0_6 arg1_8)))
(let ((?x11575 (bvadd ?x73 ?x15171)))
(and (distinct ?x11575 (_ bv0 32)) true))))))
(check-sat)
