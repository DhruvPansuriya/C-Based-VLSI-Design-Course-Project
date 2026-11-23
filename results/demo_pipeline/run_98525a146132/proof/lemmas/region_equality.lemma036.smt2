; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x162 (bvmul (_ bv4294967295 32) arg1_8)))
(let ((?x152 (bvmul (_ bv4294967295 32) arg0_10)))
(let ((?x97 (bvmul arg0_10 arg1_8)))
(let ((?x231 (bvadd ?x97 ?x152 ?x162)))
(and (distinct ?x231 (_ bv0 32)) true))))))
(check-sat)
