; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x516079 (bvmul arg0_12 arg0_15)))
(let ((?x377788 (bvmul (_ bv4294967295 32) ?x516079)))
(let ((?x461488 (bvmul arg0_15 arg0_3)))
(let ((?x355095 (bvadd ?x461488 ?x377788)))
(and (distinct ?x355095 (_ bv0 32)) true))))))
(check-sat)
