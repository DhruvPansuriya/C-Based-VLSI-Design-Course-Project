; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x184 (bvmul arg0_12 arg1_12)))
(let ((?x21129 (bvmul (_ bv4294967295 32) ?x184)))
(let ((?x127 (bvmul arg0_12 arg1_3)))
(let ((?x16087 (bvadd ?x127 ?x21129)))
(and (distinct ?x16087 (_ bv0 32)) true))))))
(check-sat)
