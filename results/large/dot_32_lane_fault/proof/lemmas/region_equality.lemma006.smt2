; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_27 () (_ BitVec 32))
(declare-fun arg0_26 () (_ BitVec 32))
(declare-fun arg0_27 () (_ BitVec 32))
(assert
 (let ((?x112 (bvmul arg0_26 arg1_27)))
(let ((?x79 (bvmul (_ bv4294967295 32) ?x112)))
(let ((?x127 (bvmul arg0_27 arg1_27)))
(let ((?x5239 (bvadd ?x127 ?x79)))
(and (distinct ?x5239 (_ bv0 32)) true))))))
(check-sat)
