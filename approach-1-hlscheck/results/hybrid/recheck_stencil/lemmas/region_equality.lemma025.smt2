; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x20033 (bvmul arg0_13 arg2_2)))
(let ((?x723511 (bvmul (_ bv4294967295 32) ?x20033)))
(let ((?x161 (bvmul arg0_13 arg2_1)))
(let ((?x726947 (bvadd ?x161 ?x723511)))
(and (distinct ?x726947 (_ bv0 32)) true))))))
(check-sat)
