; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x125 (bvmul arg0_5 arg1_1)))
(let ((?x10495 (bvmul (_ bv4294967295 32) ?x125)))
(let ((?x94 (bvmul arg0_5 arg1_4)))
(let ((?x5771 (bvadd ?x94 ?x10495)))
(and (distinct ?x5771 (_ bv0 32)) true))))))
(check-sat)
