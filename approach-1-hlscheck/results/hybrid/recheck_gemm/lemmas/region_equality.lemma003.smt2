; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x143 (bvmul arg0_3 arg1_3)))
(let ((?x206 (bvmul (_ bv4294967295 32) ?x143)))
(let ((?x55 (bvmul arg0_3 arg1_12)))
(let ((?x265 (bvadd ?x55 ?x206)))
(and (distinct ?x265 (_ bv0 32)) true))))))
(check-sat)
