; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x20673 (bvmul arg0_8 arg1_2)))
(let ((?x728472 (bvmul (_ bv4294967295 32) ?x20673)))
(let ((?x380059 (bvmul arg0_8 arg1_3)))
(let ((?x407626 (bvadd ?x380059 ?x728472)))
(and (distinct ?x407626 (_ bv0 32)) true))))))
(check-sat)
