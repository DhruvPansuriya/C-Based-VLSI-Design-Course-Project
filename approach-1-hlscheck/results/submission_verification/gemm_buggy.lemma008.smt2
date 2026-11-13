; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x102 (bvmul arg0_1 arg1_9)))
(let ((?x45 (bvmul (_ bv4294967295 32) ?x102)))
(let ((?x85 (bvmul arg0_1 arg1_6)))
(let ((?x22020 (bvadd ?x85 ?x45)))
(and (distinct ?x22020 (_ bv0 32)) true))))))
(check-sat)
