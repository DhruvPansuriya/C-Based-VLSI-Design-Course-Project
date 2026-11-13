; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x3831 (bvmul arg0_13 arg1_6)))
(let ((?x352344 (bvmul (_ bv4294967295 32) ?x3831)))
(let ((?x22818 (bvmul arg0_13 arg1_7)))
(let ((?x398322 (bvadd ?x22818 ?x352344)))
(and (distinct ?x398322 (_ bv0 32)) true))))))
(check-sat)
