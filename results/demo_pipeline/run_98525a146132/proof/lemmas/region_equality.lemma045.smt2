; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x182 (bvmul (_ bv4294967295 32) arg1_11)))
(let ((?x152 (bvmul (_ bv4294967295 32) arg0_10)))
(let ((?x112 (bvmul arg0_10 arg1_11)))
(let ((?x4660 (bvadd ?x112 ?x152 ?x182)))
(and (distinct ?x4660 (_ bv0 32)) true))))))
(check-sat)
