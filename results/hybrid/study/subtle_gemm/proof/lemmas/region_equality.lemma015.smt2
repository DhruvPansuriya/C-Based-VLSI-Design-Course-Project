; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x334547 (bvmul arg0_7 arg1_3)))
(let ((?x303724 (bvmul (_ bv4294967295 32) ?x334547)))
(let ((?x524057 (bvmul arg0_7 arg1_12)))
(let ((?x328084 (bvadd ?x524057 ?x303724)))
(and (distinct ?x328084 (_ bv0 32)) true))))))
(check-sat)
