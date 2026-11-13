; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x2614 (bvmul arg0_6 arg1_2)))
(let ((?x3273 (bvmul (_ bv4294967295 32) ?x2614)))
(let ((?x32 (bvmul arg0_6 arg1_8)))
(let ((?x10616 (bvadd ?x32 ?x3273)))
(and (distinct ?x10616 (_ bv0 32)) true))))))
(check-sat)
