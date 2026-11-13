; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x498973 (bvmul arg0_3 arg0_8)))
(let ((?x358729 (bvmul (_ bv4294967295 32) ?x498973)))
(let ((?x485029 (bvmul arg0_12 arg0_8)))
(let ((?x382170 (bvadd ?x485029 ?x358729)))
(and (distinct ?x382170 (_ bv0 32)) true))))))
(check-sat)
