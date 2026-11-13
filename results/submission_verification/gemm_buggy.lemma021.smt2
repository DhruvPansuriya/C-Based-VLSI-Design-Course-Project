; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x109 (bvmul arg0_7 arg1_11)))
(let ((?x1142 (bvmul (_ bv4294967295 32) ?x109)))
(let ((?x167 (bvmul arg0_7 arg1_14)))
(let ((?x15873 (bvadd ?x167 ?x1142)))
(and (distinct ?x15873 (_ bv0 32)) true))))))
(check-sat)
