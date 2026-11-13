; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x538872 (bvmul arg0_10 arg1_10)))
(let ((?x486760 (bvmul (_ bv4294967295 32) ?x538872)))
(let ((?x405365 (bvmul arg0_10 arg1_11)))
(let ((?x474165 (bvadd ?x405365 ?x486760)))
(and (distinct ?x474165 (_ bv0 32)) true))))))
(check-sat)
