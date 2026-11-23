; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x316624 (bvmul arg0_11 arg2_3)))
(let ((?x304338 (bvmul (_ bv4294967295 32) ?x316624)))
(let ((?x347868 (bvmul arg0_11 arg2_4)))
(let ((?x575623 (bvadd ?x347868 ?x304338)))
(and (distinct ?x575623 (_ bv0 32)) true))))))
(check-sat)
