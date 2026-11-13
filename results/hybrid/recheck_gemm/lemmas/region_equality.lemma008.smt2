; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x140 (bvmul arg0_1 arg1_9)))
(let ((?x296 (bvmul (_ bv4294967295 32) ?x140)))
(let ((?x63 (bvmul arg0_1 arg1_6)))
(let ((?x1169 (bvadd ?x63 ?x296)))
(and (distinct ?x1169 (_ bv0 32)) true))))))
(check-sat)
