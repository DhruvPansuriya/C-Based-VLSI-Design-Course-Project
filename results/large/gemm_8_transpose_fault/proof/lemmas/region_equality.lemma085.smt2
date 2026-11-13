; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_34 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_20 () (_ BitVec 32))
(assert
 (let ((?x75235 (bvmul arg0_10 arg1_34)))
(let ((?x62439 (bvmul (_ bv4294967295 32) ?x75235)))
(let ((?x63367 (bvmul arg0_10 arg1_20)))
(let ((?x23054 (bvadd ?x63367 ?x62439)))
(and (distinct ?x23054 (_ bv0 32)) true))))))
(check-sat)
