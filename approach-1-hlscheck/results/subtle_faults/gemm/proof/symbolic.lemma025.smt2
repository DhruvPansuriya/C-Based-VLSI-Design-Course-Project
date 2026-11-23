; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x174 (bvmul arg0_10 arg1_2)))
(let ((?x7227 (bvmul (_ bv4294967295 32) ?x174)))
(let ((?x93 (bvmul arg0_10 arg1_8)))
(let ((?x3249 (bvadd ?x93 ?x7227)))
(and (distinct ?x3249 (_ bv0 32)) true))))))
(check-sat)
