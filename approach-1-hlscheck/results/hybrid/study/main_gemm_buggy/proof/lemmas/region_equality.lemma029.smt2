; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x167 (bvmul arg0_11 arg1_7)))
(let ((?x1089 (bvmul (_ bv4294967295 32) ?x167)))
(let ((?x35 (bvmul arg0_11 arg1_13)))
(let ((?x21967 (bvadd ?x35 ?x1089)))
(and (distinct ?x21967 (_ bv0 32)) true))))))
(check-sat)
