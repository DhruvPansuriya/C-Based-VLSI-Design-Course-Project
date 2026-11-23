; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x149 (bvmul arg0_4 arg1_8)))
(let ((?x744 (bvmul (_ bv4294967295 32) ?x149)))
(let ((?x5042 (bvmul arg0_4 arg1_2)))
(let ((?x10501 (bvadd ?x5042 ?x744)))
(and (distinct ?x10501 (_ bv0 32)) true))))))
(check-sat)
