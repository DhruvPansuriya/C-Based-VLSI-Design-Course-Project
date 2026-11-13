; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x162 (bvmul (_ bv4294967295 32) arg1_8)))
(let ((?x193 (bvmul (_ bv4294967295 32) arg0_6)))
(let ((?x77 (bvmul arg0_6 arg1_8)))
(let ((?x6977 (bvadd ?x77 ?x193 ?x162)))
(and (distinct ?x6977 (_ bv0 32)) true))))))
(check-sat)
