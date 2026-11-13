; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x2034 (bvmul arg0_4 arg1_4)))
(let ((?x17111 (bvmul (_ bv4294967295 32) ?x2034)))
(let ((?x56 (bvmul arg0_4 arg1_1)))
(let ((?x1629 (bvadd ?x56 ?x17111)))
(and (distinct ?x1629 (_ bv0 32)) true))))))
(check-sat)
