; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x434372 (bvmul arg0_2 arg0_8)))
(let ((?x524057 (bvmul (_ bv4294967295 32) ?x434372)))
(let ((?x428523 (bvmul arg0_2 arg0_2)))
(let ((?x134697 (bvadd ?x428523 ?x524057)))
(and (distinct ?x134697 (_ bv0 32)) true))))))
(check-sat)
